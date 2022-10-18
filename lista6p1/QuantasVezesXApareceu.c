#include <stdio.h>

int a[11];

void scan(int iterador)
{
    if (iterador)
        scan(iterador - 1);

    scanf("%d", &a[iterador]);
}
int count(int n, int iterador)
{
    if(iterador < 0) return 0;
    
    return (a[iterador] == n) + count(n, iterador - 1);
}
int main()
{
    scan(10);
    printf("%d", count(a[10], 9));
}