#include <stdio.h>
#define INF 10e10

void scan(int i, int m[3][3])
{
    if (i)
        scan(i - 1, m);

    scanf("%d", &m[i / 3][i % 3]);
}
int main()
{
    int m[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d ", &m[i][j]);

    int qntd = 9;
    int media = 0, maior = -INF, diagonal = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            media += m[i][j];

            if (m[i][j] < maior)
                maior = m[i][j];

            if (i == j)
                diagonal += m[i][j];
        }
    if(maior > 0)
        delta = 1;
    else if(maior < 0)
        delta = -1;
    else
        delta = 0;

    printf("%.2lf %d %d %d", (double)media / qntd, maior, delta, diagonal);

    return 0;
}