#include <stdio.h>

#define WALL 0
#define PATH 1

int main()
{
    int n, m, c, x, y;
    scanf("%d %d", &n, &m);
    int matriz[n][m];

    for (int i = 0;i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matriz[i][j]);

    //print matrix

    scanf("%d", &c);

    char movimentos[c];	
    for (int i = 0; i < c; i++)
        scanf(" %c", &movimentos[i]);

    scanf("%d %d", &x, &y);

    for (int i = 0; i < c; i++)
    {
        switch (movimentos[i])
        {
            case 'C':
                if (x > 0 && matriz[x - 1][y] == PATH)
                    x--;
                break;
            case 'B':
                if (x + 1 < n && matriz[x + 1][y] == PATH)
                    x++;
                break;
            case 'E':
                if (y > 0 && matriz[x][y - 1] == PATH)
                    y--;
                break;
            case 'D':
                if (y + 1 < m && matriz[x][y + 1] == PATH)
                    y++;
                break;
        }
    }

    printf("(%d,%d)\n", x, y);

    // for (int i = 0;i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}