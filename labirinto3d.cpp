#include <bits/stdc++.h>

#define WALL '#'
#define PATH '.'
#define START 'S'
#define END 'E'

using namespace std;

char mapa[70][70][70];
vector<int> path;

int move(int i, int j, int k, char mapa[70][70][70], int x, int y, int z, int contador)
{
    if (x > i || y > j || z > k || x < 0 || y < 0 || z < 0 || mapa[x][y][z] == WALL)
        return 0;
    if (mapa[x][y][z] == END && printf("%d\n", contador))
        return 1;
    if (mapa[x][y][z] == PATH)
    {
        mapa[x][y][z] = WALL;
        if (move(i, j, k, mapa, x + 1, y, z, contador + 1))
        {
            path.push_back(0);
            return 1;
        }
        if (move(i, j, k, mapa, x - 1, y, z, contador + 1))
        {
            path.push_back(1);
            return 1;
        }
        if (move(i, j, k, mapa, x, y + 1, z, contador + 1))
        {
            path.push_back(2);
            return 1;
        }
        if (move(i, j, k, mapa, x, y - 1, z, contador + 1))
        {
            path.push_back(3);
            return 1;
        }
        if (move(i, j, k, mapa, x, y, z + 1, contador + 1))
        {
            path.push_back(4);
            return 1;
        }
        if (move(i, j, k, mapa, x, y, z - 1, contador + 1))
        {
            path.push_back(5);
            return 1;
        }
        mapa[x][y][z] = PATH;
    }
    return 0;
}

int main()
{
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);

    // Read the mapa
    for (int n = 0; n < i; n++)
        for (int m = 0; m < j; m++)
            for (int p = 0; p < j; p++)
                scanf(" %c", &mapa[n][m][p]);

    // mapa[0][0][0] = START;
    mapa[--i][--j][--k] = END;

    // Find the path
    move(i, j, k, mapa, 0, 0, 0, 0);

    // Print the path
    char directions[6] = {'F', 'B', 'D', 'U', 'R', 'L'};
    
    for (int n = path.size() - 1; n >= 0; n--)
        printf("%c%s", directions[path[n]], !n ? "" : " -> ");

    return 0;
}


    // Print the map
    // printf("PRINTANDO O MAPA\n");
    // for (int n = 0; n < i; n++)
    // {
    //     for (int m = 0; m < j; m++)
    //         printf("%s\n", map[n][m]);
    //     printf("\n");
    // }