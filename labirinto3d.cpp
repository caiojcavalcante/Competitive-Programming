#include <bits/stdc++.h>

#define WALL '#'
#define PATH '.'
#define END 'E'

using namespace std;

char mapa[70][70][70
vector<int> path;
int moves[6] {1, 0, 0, -1, 0, 0};
char directions[6] {'F', 'L', 'U', 'B', 'R', 'D'};

int move(int i, int j, int k, char mapa[70][70][70], int x, int y, int z, int contador)
{
    if (x > i || y > j || z > k || x < 0 || y < 0 || z < 0 || mapa[x][y][z] == WALL)
        return 0;

    if (mapa[x][y][z] == END && printf("%d\n", contador))
        return 1;

    if (mapa[x][y][z] == PATH) {
        mapa[x][y][z] = WALL;

        for (int m = 0;m < 6; m++) {
            if (move(i, j, k, mapa, x + moves[m % 6], y + moves[(m + 1) % 6], z + moves[(m + 2) % 6], contador + 1)) {
                path.push_back(m);
                return 1;
            }
        }
        mapa[x][y][z] = PATH;
    }
    return 0;
}

int main()
{
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    // Read the map
    for (int n = 0; n < i; n++)
        for (int m = 0; m < j; m++)
            for (int p = 0; p < k; p++)
                scanf(" %c", &mapa[n][m][p]);

    mapa[--i][--j][--k] = END;

    // Find the path
    move(i, j, k, mapa, 0, 0, 0, 0);

    // Print the path
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