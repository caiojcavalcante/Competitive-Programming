#include <stdio.h>
#include <math.h>

int main()
{
    int s, i, j, res = 0;

    scanf("%d%d%d", &s, &i, & j);

    s = pow(2, s);

    while(i != s / 2 || j != s / 2)
    {
        i *= 2;
        if (i > s)
            i -= s;

        j *= 2;
        if (j > s)
            j -= s;

        res++;
    }
    printf("%d\n", res);
    return 0;
}