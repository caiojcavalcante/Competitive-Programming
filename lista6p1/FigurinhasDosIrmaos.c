#include <stdio.h>

a[1000005];
repetidas[1000005];

void scan(int iterador)
{
    if (iterador)
        scan(iterador - 1);

    // o codigo ta passando endereco
    // pq a[n] é uma variavel
    scanf("%d", &a[iterador]);
    // mas eu poderia usar meu ponteiro a, pq a é um ponteiro
    // ficaria assim
    //scanf("%d", a + iterador);
}
//    declaro que vou receber um endereco v
int count(int paridade, int iterador, int* acc)
{
    if (iterador < 0) return 0;

    if(!repetidas[a[iterador]] && (a[iterador] & 1) == paridade)
    {
        repetidas[a[iterador]] = 1;
        *acc += a[iterador];
    }
    //   x & 1 é o mesmo que x % 2 so que mais rapido
    //  aqui testa se é par     v    //veja q na recursao eu n chamo &acc, é so acc
    return ((a[iterador] & 1) == paridade) + count(paridade, iterador - 1, acc);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    //declaro meus valores como zero v                 v
    int figurinhas, impares, pares, soma_impares = 0, soma_pares = 0;
    scanf("%d", &figurinhas);
    scan(figurinhas);
    //passo os dois enderecos como argumento v
    printf("%d\n", count(0, figurinhas - 1, &soma_pares));
    printf("%d\n", count(1, figurinhas - 1, &soma_impares));
    printf("%d\n", max(soma_impares, soma_pares));
    return 0;
}