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
    int media = 0, menor = INF, diagonal = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if(m[i][j] > 0)
                media += m[i][j];
            else
                qntd--;

            if (m[i][j] < menor)
                menor = m[i][j];

            if (i != j)
                diagonal += m[i][j];
        }

    printf("%.2lf %d %d %d", (double)media / qntd, menor, !(menor & 1), diagonal);

    return 0;
}