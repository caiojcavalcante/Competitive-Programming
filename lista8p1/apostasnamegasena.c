#include <stdio.h>
#include <string.h>

int is_in(int* a, int n)
{
    if(*a == 0)
        return 0;
    if(*a == n)
        return 1;
    return is_in(a + 1, n);
}

int main()
{
    int n, num_apostas, ans = 0;
    scanf("%d", &n);
    num_apostas = n;
    int apostas[n][12];
    int resposta[6];
    memset(apostas, 0, sizeof(apostas));
    while(n--)
    {
        int i = 0;
        while(1)
        {
            scanf("%d", &apostas[n][i++]);
            if(getchar() != ',')
                break;
        }
    }

    for(int i = 0; i < 6; i++)
        scanf("%d", &resposta[i]);

    for(int i = 0; i < num_apostas; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(j < 6 && !is_in(apostas[i], resposta[j]))
                break;
            if(j == 6)
                ans++;
        }
    }
    printf("Total de ganhadores: %d", ans);
    return 0;
}