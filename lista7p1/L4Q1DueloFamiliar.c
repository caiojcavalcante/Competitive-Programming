#include <stdio.h>


int checa_validez(int matriz[3][3])
{
    if(!matriz[1][1]) // se o centro estiver vazio
        return 0;
    if(matriz[0][0] && !matriz[2][2]) //se nao formar diagonal
        return 0;
    if(matriz[0][2] && !matriz[2][0]) //se nao formar diagonal
        return 0;
    if(matriz[0][0] && matriz[0][2]) // se tiver multiplas diagonais
        return 0;
    if(matriz[0][1] || matriz[1][0] || matriz[1][2] || matriz[2][1]) // se tiver fora da diagonal
        return 0;
    if(matriz[0][0] || matriz[0][2]) // se tem diagonal
        return 1;
    return 0; // se nao tem diagonal
}
int main()
{
    int vida_luke, vida_vader, sabre_luke[3][3], sabre_vader[3][3], ataque_luke, ataque_vader, input = 1;

    scanf("%d %d", &vida_luke, &vida_vader);
        
    while(input == 1)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                input = scanf("%d", &sabre_luke[i][j]);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                input = scanf("%d", &sabre_vader[i][j]);
                
        ataque_luke = checa_validez(sabre_luke);
        ataque_vader = checa_validez(sabre_vader);

        if(ataque_luke && !ataque_vader)
            vida_vader -= 15;

        if(!ataque_luke && ataque_vader)
            vida_luke -= 15;
    }

    if(vida_luke > vida_vader)
        printf("Luke Skywalker venceu.");
    else if (vida_luke < vida_vader)
        printf("Darth Vader venceu.");
    else
        printf("Houve empate.");

    return 0;
}