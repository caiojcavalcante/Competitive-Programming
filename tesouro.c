#include <stdio.h>

#define WALL '#'
#define PATH '.'
#define BRONZE 'b'
#define SILVER 'p'
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
        case SILVER:
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

    char storedPosition = map[x][y];

    // printf("%d %d\n", x, y);

    map[x][y] = WALL;

    int north = move(i, j, map, x-1, y);
    int south = move(i, j, map, x+1, y);
    int east = move(i, j, map, x, y+1);
    int west = move(i, j, map, x, y-1);

    map[x][y] = storedPosition;

    return (max(north, south, east, west) + eval(map[x][y]));
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char map[m][n];

    for(int i = 0; i < m; i++)
        scanf(" %[^\n]s", map[i]);

    // PRINT MATRIX
    // for(int i = 0; i < m; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //         printf("%c ", map[i][j]);
    //     printf("\n");
    // }
    printf("%d\n", move(m, n, map, 0, 0));

    return 0;
}
