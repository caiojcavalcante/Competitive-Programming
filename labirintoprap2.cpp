#include <bits/stdc++.h>

#define WALL '#'
#define PATH '.'
#define END 'O'

using namespace std;

char mapa[505][505];
char directions[4] {'v', '<', '^', '>'};
char path_directions[4] {'D', 'L', 'U', 'R'};
int moves[4] {1, 0, -1, 0};
vector <char> path;

bool move(int i, int j, char mapa[505][505], int x, int y)
{
    // Check if position is valid
    if(x < 0 || x >= i || y < 0 || y >= j || mapa[x][y] == WALL)
        return false;

    // Check if position is solution
    if(mapa[x][y] == END)
        return true;

    // Mark position as visited
    mapa[x][y] = WALL;

    // Try to move in all directions
    for (int m = 0;m < 4; m++) 
        if (move(i, j, mapa, x + moves[m % 4], y + moves[(m + 1) % 4]))
        {
            // If postion leads to solution, add direction to path
            mapa[x][y] = directions[m];
            path.push_back(path_directions[m]);
            return true;
        }
    // If position doesn't lead to solution, unmark it
    mapa[x][y] = PATH;
    // Tell the caller that this position doesn't lead to solution
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

    move(i, j, mapa, 0, 0) || printf("Nao tem solucao\n");

    printf("\n");
    // Print the map
    for (int n = 0; n < i; n++)
    {
        for (int m = 0; m < j; m++)
            printf(" %c", mapa[n][m]);
        printf("\n");
    }

    printf("\n");
    // Print the path
    for (char c: path)
        printf("%c ", c);
    printf("\n");
}