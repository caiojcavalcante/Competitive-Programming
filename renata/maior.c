#include <stdio.h>

int main()
{
    int a, b, maior;
    scanf("%d%d", &a, &b);

    if (a < b)
    {
        maior = b;
    }
    else
    {
        maior = a;
    }

    printf("%d", maior);
    return 0;
}