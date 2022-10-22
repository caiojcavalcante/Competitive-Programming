#include <stdio.h>

int somaDigitos(int n)
{
    return n ? n % 10 + somaDigitos(n / 10) : 0;
}
void scan(int iterador, int a[10000])
{
    if (iterador)
        scan(iterador - 1);
    
    scanf("%d", &a[iterador]);
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[10000];
    scan(n, a);
    scanf("%d", &i);
    printf("%d", somaDigitos(a[i]));
    return 0;
}