#include <stdio.h>
#include <string.h>

char repetidas[13005];

int max(int a, int b)
{
    return a > b ? a : b;
}
void scan(int iterador, int* impares, int* pares, int* soma_impares, int* soma_pares)
{
    int figurinha;
    if(scanf("%d", &figurinha) == EOF) return;
    if(figurinha & 1)
    {
        (*impares) = (*impares) + 1;
        if(repetidas[figurinha] == 0)
            (*soma_impares) = (*soma_impares) + figurinha;
    }
    else
    {
        (*pares) = (*pares) + 1;
        if (repetidas[figurinha] == 0)
            (*soma_pares) = (*soma_pares) + figurinha;
    }
    repetidas[figurinha] = 1;
    if(iterador) scan (iterador - 1, impares, pares, soma_impares, soma_pares);
}
int main()
{
    memset(repetidas, 0, sizeof(repetidas));


    int figurinhas, impares = 0, pares = 0, soma_impares = 0, soma_pares = 0;
    scanf("%d", &figurinhas);

    scan(figurinhas, &impares, &pares, &soma_impares, &soma_pares);

    printf("%d\n%d\n%d\n", pares, impares, max(soma_impares, soma_pares));
    return 0;
}