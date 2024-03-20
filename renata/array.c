#include <stdio.h>

int main()
{
    int numeros[6];
    int maior;
    int menor;
    // Loop para ler 6 números
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &numeros[i]);
    }

    maior = numeros[0];
    menor = numeros[0];

    for (int i = 0; i < 6; i++)
    {
        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }

        if (numeros[i] < menor)
        {
            menor = numeros[i];
        }
    }
    
    printf("%d %d", maior, menor);

    return 0;
}
