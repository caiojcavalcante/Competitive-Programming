#include <stdio.h>

int main()
{
    int n , ans = 0, aux, impares = 0, pares = 1;
    for(scanf("%d", &aux) != EOF)
    {
        if(aux & 1)
        {
            impares++;
            ans += pares;
        }
        else
        {
            pares++;
            ans += impares;
        }
        printf("%d\n", pares);
    }
    return 0;
}