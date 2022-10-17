#include <bits/stdc++.h>

#define WALL '#'
#define PATH '.'
#define END 'E'

using namespace std;

char mapa[100][100];
int moves[4] {1, 0, -1, 0};

bool move(int i, int j, char mapa[100][100], int x, int y)
{
    if(x < 0 || x >= i || y < 0 || y >= j || mapa[x][y] == WALL)
        return false;
    if(mapa[x][y] == END)
        return true;

    mapa[x][y] = WALL;

    for (int m = 0;m < 6; m++) 
        if (move(i, j, mapa, x + moves[m % 4], y + moves[(m + 1) % 4]))
            return true;

    mapa[x][y] = PATH;

    return false;
}

int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    // Read the map
    for (int n = 0; n < i; n++)
        for (int m = 0; m < j; m++)
            scanf(" %c", &mapa[n][m]);

    mapa[i - 1][j - 1] = END;

    cout << (move(i, j, mapa, 0, 0) ? "Yes" : "No") << endl;
    return 0;
}