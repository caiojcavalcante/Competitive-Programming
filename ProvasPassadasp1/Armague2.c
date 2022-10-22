#include <stdio.h>
#define WILL 0
#define GABRIEL 1

int mdc(int a, int b) {
    return b ? mdc(b, a % b) : a;
}
int isPrime(int n, int div) {
    if(div * div > n)
        return 1;
    if(n % div == 0)
        return 0;
    return isPrime(n, div + 1);
}
int buff(int habilidade, int* ataque_jogador, int* vida_jogador, int* vida_inimigo, int numero_round)
{
    switch (habilidade)
    {
        case 1://Se for um round primo, poderá atacar 2 vezes.
            if(isPrime(numero_round, 2))
                *vida_inimigo -= *ataque_jogador;
            break;
        case 2:
            if(mdc(*vida_jogador, *vida_inimigo) == 1)
                *ataque_jogador += 25;
            break;
        case 3:
            if(isPrime(*ataque_jogador, 2) || isPrime(*vida_jogador, 2))
                *ataque_jogador += 10;
            break;
    }
    return 0;
}

int round(int numero_round, int quem_joga, int habilidade_will, int ataque_will, int vida_will, int habilidade_gabriel, int ataque_gabriel, int vida_gabriel)
{
    if (vida_will    <= 0) return 0;
    if (vida_gabriel <= 0) return 1;
    //buff
    quem_joga == WILL && buff(habilidade_will, &ataque_will, &vida_will, &vida_gabriel, numero_round);
    quem_joga == GABRIEL && buff(habilidade_gabriel, &ataque_gabriel, &vida_gabriel, &vida_will, numero_round);
    //ataque
    vida_gabriel -= ataque_will * (quem_joga == WILL);
    vida_will -= ataque_gabriel * (quem_joga == GABRIEL);

    return round(numero_round + 1, !quem_joga, habilidade_will, ataque_will, vida_will, habilidade_gabriel, ataque_gabriel, vida_gabriel);
}
int armague(int rodadas)
{
    int quem_comeca, habilidade_will, habilidade_gabriel, vida_will, vida_gabriel, ataque_will, ataque_gabriel;
    if(!rodadas || scanf("%d%d%d%d%d%d%d", &quem_comeca, &habilidade_will, &ataque_will, &vida_will, &habilidade_gabriel, &ataque_gabriel, &vida_gabriel) == EOF) return 0;
    return armague(rodadas - 1) + round(1, quem_comeca - 1, habilidade_will, ataque_will, vida_will, habilidade_gabriel, ataque_gabriel, vida_gabriel);
}
int main()
{
    int rodadas;
    scanf("%d", &rodadas);
    int ret = armague(rodadas);
    
    printf("Will ganhou %d rodadas\nGabriel ganhou %d rodadas", ret, rodadas - ret);
}