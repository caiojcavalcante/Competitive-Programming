#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; i++)
int main()
{
    int n, jogadas, x = 0, y = 0, d, qntd_movimentos;
    scanf("%d", &n);
    n = sqrt(n);
    int a[n][n];
    rep(i, n)rep(j, n){
        scanf("%d", &a[i][j]);
    }
    char dado[4], move;
    rep(i, 4)
        scanf(" %c", &dado[i]);

    scanf("%d", &jogadas);
    rep(i, jogadas)
    {
        scanf("%d %d", &qntd_movimentos, &d);
        move = dado[d - 1];
        for(int j = 0; j < qntd_movimentos; j++)
        {
            if(move == 'D')
            {
                if(y + 1 < n && a[x][y + 1] != 0)
                    y++;
            }
            else if(move == 'E')
            {
                if(y - 1 >= 0 && a[x][y - 1] != 0)
                    y--;
            }
            else if(move == 'C')
            {
                if(x - 1 >= 0 && a[x - 1][y] != 0)
                    x--;
            }
            else if(move == 'B')
            {
                if(x + 1 < n && a[x + 1][y] != 0)
                    x++;
            }
        }
    }
    printf("%s\n", (x == n - 1 && y == n - 1) ? "EU PASSEI EM P1\n" : "AINDA TENHO CHANCE NA REAV\n");
    return 0;
}