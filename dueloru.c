#include <stdio.h>
#define NUM_CARTAS 3
#define TULIO 0
#define PEDRO 1

typedef enum
{
    GUERREIRO = 1,
    MAGO = 2,
    ARQUEIRO = 3
} Classe;

typedef struct carta
{
    Classe classe;
    double ataque;
    double vida;
} Carta;

void read_card(Carta *carta)
{
    scanf(" %d %lf %lf", &carta->classe, &carta->ataque, &carta->vida);
}

void print_card(Carta *carta)
{
    printf(" %d %lf %lf", carta->classe, carta->ataque, carta->vida);
}

void buff(Carta *carta1, Carta *carta2)
{
    if (carta1->classe == carta2->classe)
    {
        return;
    }
    if (carta1->classe == GUERREIRO && carta2->classe == ARQUEIRO)
    {
        // Caso 1: Duelo entre Guerreiro e Arqueiro.
        // O guerreiro recebe um aumento de 30% em relação a sua vida.
        carta1->vida *= 1.3;
    }
    else if (carta1->classe == ARQUEIRO && carta2->classe == MAGO)
    {
        // Caso 2: Duelo entre Arqueiro e Mago.
        // O arqueiro recebe um aumento de 25% em relação ao seu ataque.
        carta1->ataque *= 1.25;
    }
    else if (carta1->classe == MAGO && carta2->classe == GUERREIRO)
    {
        // Caso 3: Duelo entre Mago e Guerreiro.
        // O mago recebe um aumento de 15% em sua vida e em seu ataque.
        carta1->ataque *= 1.15;
        carta1->vida *= 1.15;
    }
    else
    {
        // Se não houve vantagem para a carta 1, haverá para a carta 2
        buff(carta2, carta1);
    }
}

int duelo(Carta carta1, Carta carta2)
{
    // Iniciamos efetuando o buff
    buff(&carta1, &carta2);

    if (carta1.vida <= carta2.vida &&
        carta1.ataque >= carta2.vida)
    {
        return PEDRO;
    }
    if (carta2.vida <= carta1.vida &&
        carta2.ataque >= carta1.vida)
    {
        return TULIO;
    }

    carta1.vida -= carta2.ataque;
    carta2.vida -= carta1.ataque;

    if (carta1.vida > carta2.vida)
    {
        return PEDRO;
    }
    if (carta1.vida < carta2.vida)
    {
        return TULIO;
    }
    if (carta1.ataque > carta2.ataque)
    {
        return PEDRO;
    }
    if (carta1.ataque < carta2.ataque)
    {
        return TULIO;
    }
    return TULIO;
}
int main()
{
    int score_pedro = 0, score_tulio = 0;
    Carta pedro[NUM_CARTAS], tulio[NUM_CARTAS];

    for (int i = 0; i < NUM_CARTAS; i++)
    {
        read_card(&pedro[i]);
    }
    for (int i = 0; i < NUM_CARTAS; i++)
    {
        read_card(&tulio[i]);
    }

    for (int rodada = 0; rodada < NUM_CARTAS; rodada++)
    {
        printf("Rodada%d: ", rodada + 1);

        if (duelo(pedro[rodada], tulio[rodada])) // pedro venceu
        {
            printf("Pedro\n");
            score_pedro++;
        }
        else // tulio venceu
        {
            printf("Tulio\n");
            score_tulio++;
        }
    }

    if (score_pedro > score_tulio)
    {
        printf("Pedro vitorioso\n");
    }
    else if (score_pedro)
    {
        printf("Tulio vitorioso\n");
    }

    return 0;
}