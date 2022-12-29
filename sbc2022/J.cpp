#include <stdio.h>

int main()
{
    int rodada, joao, joao2, maria, maria2, mesa, res = -1, cartas[14] = {0};

    scanf("%d%d%d%d%d", &rodada, &joao, &joao2, &maria, &maria2);

    cartas[joao]++;
    cartas[joao2]++;
    cartas[maria]++;
    cartas[maria2]++;

    if(joao > 10)
        joao = 10;
    if(joao2 > 10)
        joao2 = 10;
    if(maria > 10)
        maria = 10;
    if(maria2 > 10)
        maria2 = 10;

    joao += joao2;

    maria += maria2;

    for(int i = 0; i < rodada; i++)
    {
        scanf("%d", &mesa);

        cartas[mesa]++;

        if(mesa > 10)
            mesa = 10;

        joao += mesa;
        maria += mesa;
    }

    int j;

    for(int i = 0; i < 13; i++)
    {
        j = i;

        if(i > 10)
            j = 10;

        if(cartas[i] >= 4)
            continue;

        if((j + joao > 23 && j + maria <= 23) || j + maria == 23)
        {
            res = i;
            break;
        }
    }

    printf("%d\n", res);

    return 0;
}