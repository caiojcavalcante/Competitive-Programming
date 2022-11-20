#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int n, m, k, a, b, x = 0, y = 0;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    scanf("%d", &k);

    char movimentos[k];

    for(int i = 0; i < k; i++)
        scanf(" %c", &movimentos[i]);

    scanf("%d%d", &a, &b);

    for(int i = 0; i <= k; i++)
    {
        if(x == a && y == b)
        {
            printf("Cheguei com %d movimentos\n", i);
            break;
        }
        if(i == k)
        {
            printf("Nao cheguei\n");
            break;
        }

        x += movimentos[i] == 'C' ? -1 : movimentos[i] == 'B' ? 1 : 0;
        y += movimentos[i] == 'D' ? 1 : movimentos[i] == 'E' ? -1 : 0;

        x = min(max(x, 0), n - 1);
        y = min(max(y, 0), m - 1);

        if(matrix[x][y] != 0)
        {
            matrix[x][y]--;
            x -= movimentos[i] == 'C' ? -1 : movimentos[i] == 'B' ? 1 : 0;
            y -= movimentos[i] == 'D' ? 1 : movimentos[i] == 'E' ? -1 : 0;
        }
    }
    return 0;
}