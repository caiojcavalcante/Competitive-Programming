#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main ()
{
    int matriz [3][3];
    int i, j, maior = 0, valor; 
    double soma = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf ("%d", &valor);
            matriz[i][j] = valor;
            soma = soma + matriz [i] [j];
        }
    }
    maior = matriz[0][0];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz [i] [j];
            }
        }
    }

    printf ("%.2lf %d\n", soma / 9, maior);
}