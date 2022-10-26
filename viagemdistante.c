#include <stdio.h>

int main()
{
    int a, g, p, v = 0;
    scanf("%d%d%d", &a, &g, &p);
    while(g > 0)
    {
        v += a;
        g -= v;
        p += v;
    }
    printf("%d", p);
    return 0;
}