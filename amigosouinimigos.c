#include <stdio.h>

int moves[4] = {-1, 0, 1, 0};

int main() 
{
    int a = 1, b = 2, n, x = 0, y = 0;
    scanf("%d", &n);

    int passo = 0, acc = 1, movimento = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", x, y);
        x += moves[movimento % 4];
        y += moves[(movimento + 2) % 4];
        passo++;
        if(passo == acc)
        {
            movimento++;
            passo = 0;
            acc++;
        }
    }
    return 0;
}