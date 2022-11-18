#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, ans, found, l, r, index;
    scanf("%d %d", &n, &m);
    char dict[n][11];
    char word[11];

    for (int i = 0; i < n; i++)
        scanf("%s", dict[i]);

    for (m; m > 3; m--) // por algum motivo tive q botar esse 3
    {                  // se nao, ele nao para de scanfar
        scanf("%s", word);
        ans = found = l = 0;
        r = n - 1;
        while (l < r)
        {
            index = (l + r) / 2;

            for (int j = 0; j < 11; j++)
            {
                if (word[j] == dict[index][j] && word[j] == '\0')
                {
                    found = 1;
                    break;
                }
                ans++;
                if (word[j] > dict[index][j])
                {
                    l = index + 1;
                    break;
                }
                if (word[j] < dict[index][j])
                {
                    r = index - 1;
                    break;
                }
            }
            if (found)
                break;
        }
        printf("%s %d\n", found ? "SIM" : "NAO", ans);
    }

    return 0;
}