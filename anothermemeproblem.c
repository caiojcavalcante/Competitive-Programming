#include <stdio.h>

int main()
{
    char s0[100];

    int left_limit, right_limit, ans = 0, n;

    scanf("%d", &n);

    while(n--)
    {    
        scanf("%d %d", &left_limit, &right_limit);

        for(int i = 1; i <= left_limit; i++)
        {
            for (int j = 1; j <= right_limit; j++)
            {
                sprintf(s0, "%d%d", i, j);
                if(i * j + i + j == atoi(s0)) ans++;
            }
        }
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}