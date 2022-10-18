#include <stdio.h>

a[1000005];
repetidas[1000005];

void scan(int iterador)
{
    if (iterador)
        scan(iterador - 1);

    scanf("%d", &a[iterador]);
}
int count(int paridade, int iterador, int* acc)
{
    if (iterador < 0) return 0;

    
    if(!repetidas[a[iterador]] && (a[iterador] & 1) == paridade)
    {
        repetidas[a[iterador]] = 1;
        *acc += a[iterador];
    }

    return ((a[iterador] & 1) == paridade) + count(paridade, iterador - 1, acc);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int figurinhas, impares, pares, soma_impares = 0, soma_pares = 0;
    scanf("%d", &figurinhas);
    scan(figurinhas);
    printf("%d\n", count(0, figurinhas - 1, &soma_pares));
    printf("%d\n", count(1, figurinhas - 1, &soma_impares));
    printf("%d\n", max(soma_impares, soma_pares));
    return 0;
}