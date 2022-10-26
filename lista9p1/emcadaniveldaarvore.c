#include <stdio.h>
#include <string.h>

<<<<<<< Updated upstream
#define LEFT 0
#define RIGHT 1
#define MAIOR 0
#define MENOR 1
#define INF 1000000000

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
void get_tree(int nivel, int node, int m[][2], int niveis[][2], int data[])
{
    niveis[nivel][MAIOR] = max(niveis[nivel][MAIOR], data[node]);
    niveis[nivel][MENOR] = min(niveis[nivel][MENOR], data[node]);

    if(m[node][LEFT] != -1)
        get_tree(nivel + 1, m[node][LEFT], m, niveis, data);
    if(m[node][RIGHT] != -1)
        get_tree(nivel + 1, m[node][RIGHT], m, niveis, data);
=======
int profundidade(int n, int m[][3], int i, int j)
{
    if (i == -1)
        return 0;
    return 1 + profundidade(n, m, m[i][j], j);
>>>>>>> Stashed changes
}
int main()
{
    int n;
    scanf("%d", &n);
<<<<<<< Updated upstream

    int m[n][2];
    int data[n];
    int niveis[n][2];

    memset(niveis, 0, sizeof(niveis));
    memset(data, 0, sizeof(data));
    memset(m, -1, sizeof(m));
    
    for(int i = 0; i < n; i++)
        niveis[i][MENOR] = INF;

    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &data[i], &m[i][0], &m[i][1]);

    get_tree(0, 0, m, niveis, data);

    for(int i = 0; i < n; i++)
        if(niveis[i][MAIOR] != 0)
            printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, niveis[i][MAIOR], niveis[i][MENOR]);
=======
    int matriz[n][3];
    int camadas[n][n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);
    }
>>>>>>> Stashed changes
    return 0;
}