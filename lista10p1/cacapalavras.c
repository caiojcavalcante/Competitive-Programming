#include <stdio.h>
#include <string.h>

int main()
{
    int direction, diff, n, m, ans, found, l, r, index;
    scanf("%d %d", &n, &m);
    char dict[n][11];
    char word[11];

    for (int i = 0; i < n; i++)
        scanf("%s", dict[i]);

    for (int i = 0; i < m; i++)
    {
        scanf("%s", word);
        ans = found = l = direction = 0;
        r = n - 1;
        while (r >= l)
        {
            index = (l + r) / 2;

            for(int k = 0; k < 11; k++)
            {
                if(dict[index][k] != word[k])
                {
                    direction = dict[index][k] - word[k];
                    break;
                }
                ans++;
                if(dict[index][k] == '\0' && word[k] == '\0')
                {
                    found = 1;
                    break;
                }
                printf("%c", dict[index][k]);
            }
            if(direction > 0)
                r = index - 1;

            if(direction < 0)
                l = index + 1;
            printf("r: %d, l: %d\n", r, l);
        }
        printf("%s %d\n", found ? "SIM" : "NAO", ans);
    }

    return 0;
}