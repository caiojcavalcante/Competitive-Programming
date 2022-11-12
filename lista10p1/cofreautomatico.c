#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int numeros[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &numeros[i]);

    char dir;
    int casa_atual = 0, acrescimo;

    while(1)
    {
        scanf(" %c%d", &dir, &acrescimo);
        if (dir == 'S')
            break;

        casa_atual = (((casa_atual + (dir == 'D' ? -acrescimo : acrescimo)) % n) + n) % n;

        for(int i = 0; i < n; i++)
            printf("%d ", numeros[(casa_atual + i) %  n]);

        printf("\n");
    }
    return 0;
}