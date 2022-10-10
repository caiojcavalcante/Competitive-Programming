#include <stdio.h>

#define WALL '#'
#define PATH '.'
#define BRONZE 'b'
#define PRATA 'p'
#define GOLD 'o'
#define DIAMOND 'd'

int max(int a, int b, int c, int d)
{
    if (b > a) a = b; 
    if (c > a) a = c;
    if (d > a) a = d;
    return a;
}
int eval(char n)
{
    switch (n){
        case BRONZE:
            return 1;
        case PRATA:
            return 5;
        case GOLD:
            return 10;
        case DIAMOND:
            return 50;
        default:
            return 0;
    }
}
int move(int i, int j, char map[][j], int x, int y)
{
    if(x < 0 || x >= i || y < 0 || y >= j || map[x][y] == WALL) return 0;

    int money = eval(map[x][y]);

    map[x][y] = WALL;

    return (max(move(i, j, map, x + 1, y), move(i, j, map, x - 1, y), move(i, j, map, x, y + 1), move(i, j, map, x, y - 1)) + money);
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char map[m][++n];

    for(int i = 0; i < m; i++)
        gets(map[i]);

    // PRINT MATRIX
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%c ", map[i][j]);
        printf("\n");
    }
    printf("%d\n", move(m, n, map, 0, 0));

    return 0;
}
