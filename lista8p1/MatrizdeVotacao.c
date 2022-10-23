#include <stdio.h>

void scan_matrix(int iterator, int i, int j, int m[i][j])
{
    if (iterator)
    {
        scan_matrix(iterator - 1, i, j, m);
    }
    scanf("%d", &m[iterator / i][iterator % j]);
}
void print_matrix(int i, int j, int m[i][j])
{
    for(int k = 0; k < j; k++)
    {
        for(int l = 0; l < i; l++)
            printf("%d ", m[k][l]);

        printf("\n");
    }
}
void print(int i, int j, int m[][j], int acc)
{
    printf("%d\n", m[i][j]);
    if (i)
        print(i - 1, j, m, acc + m[i][j]);
    else
        printf("Princesa %d: %d voto(s)", j, acc);
}
int main()
{
    int i, j;
    scanf("%d %d", &i, &j);
    int matriz[i][j];
    scan_matrix(i - 1, j - 1, matriz);
    print_matrix(i, j, matriz);
    // print(i - 1, j - 1, matriz, 0);
    return 0;
}