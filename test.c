#include <bits/stdc++.h>

using namespace std;
// int main()
// {
//     unsigned long long int freq[256] = {0};
//     char buffer;
//     while(scanf(" %c", &buffer) != EOF)
//         freq[buffer]++;
//     for(int i = 0; i < 256; i++)
//         if(freq[i] & 1)
//         {
//             printf("%c\n", i);
//             break;
//         }
//     return 0;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     char ans = '\0', buffer;

//     while(scanf(" %c", &buffer) != EOF)
//         ans ^= buffer;

//     printf("%c\n", ans);
//     return 0;
// }
// int main()
// {
//     //gera casos de teste
//     ios_base::sync_with_stdio(false);
//     cout.tie(NULL);
//     for(int i = 0; i < 10000000; i++)
//         cout << "teclado";
//     cout << endl;
//     for(int i = 0; i < 10000000; i++)
//     {
//         cout << "teclado";
//         if(i == 43943439)
//             cout << 'e';
//     }
//     cout << endl;
// }
#include <stdio.h>
#define PLAYER 2
#define EMPTY 0
#define NPC 1

int move(int moves[], int x, int y, int n, int m[][n])
{
    int pos_x = x, pos_y = y, kills = 0;
    for(int i = 0; i < 4; i++)
    {
        x = pos_x; // sempre começa no lugar onde o jogador está
        y = pos_y; 
        while(1)
        {
            x += moves[(i + 0) % 4]; //mesmo que moves[i], mas fica mais claro
            y += moves[(i + 1) % 4];

            if(x < 0 || x >= n || y < 0 || y >= n) // se sair do mapa
                break;

            if(m[x][y] == PLAYER) // se encontrar outro jogador
                break;

            if(m[x][y] == NPC) // se encontrar um npc
            {
                m[x][y] = EMPTY; // mata o npc
                kills++; // conta a morte
                break;
            }
        }
    }
    return kills;
}

void solve(int n, int m[][n], int aziul_x, int aziul_y, int nosredna_x, int nosredna_y)
{
    int moves_r[4] = {1, 0, -1, 0}, moves_a[4] = {1, 1, -1, -1}, temp_x, temp_y, aziul = 0, nosredna = 0;

    m[aziul_x][aziul_y] = PLAYER;
    m[nosredna_x][nosredna_y] = PLAYER;

    aziul = move(moves_a, aziul_x, aziul_y, n, m);

    nosredna = move(moves_r, nosredna_x, nosredna_y, n, m);

    printf("aziul matou %d\nnosredna matou %d\n", aziul, nosredna);
}

int main()
{
    int n, aziul_x, aziul_y, nosredna_x, nosredna_y;
    scanf("%d", &n);
    int m[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    scanf("%d %d %d %d", &aziul_x, &aziul_y, &nosredna_x, &nosredna_y);

    solve(n, m, aziul_x, aziul_y, nosredna_x, nosredna_y);
    return 0;
}