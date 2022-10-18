#include <stdio.h>

int a[6];

int mn(int a, int b)
{
    return a < b ? a : b;
}
int mx(int a, int b)
{
    return a > b ? a : b;
}
void scan(int iterador)
{
    if (iterador)
        scan(iterador - 1);

    scanf("%d", &a[iterador]);
}
int min(int iterador)
{
    if (iterador == 0)
        return a[0];
    return mn(a[iterador], min(iterador - 1));
}
int max(int iterador)
{
    if (iterador == 0)
        return a[0];
    return mx(a[iterador], max(iterador - 1));
}
int main()
{
    scan(5);
    printf("%d\n%d\n", min(5), max(5));
}