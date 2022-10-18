#include <stdio.h>

int a[100000];

void scan(int iterador)
{
    if (iterador)
        scan(iterador - 1);

    scanf("%d", &a[iterador]);
}

void print(int iterador)
{
    printf("%d ", a[iterador - 1]);

    if (iterador - 1)
        print(iterador - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    scan(n);
    print(n);
}