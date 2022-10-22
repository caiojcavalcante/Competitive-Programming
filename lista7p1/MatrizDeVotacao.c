#include <stdio.h>

void scan_matriz(int iterador, int linhas, int colunas, int matriz[linhas][colunas])
{
    if(iterador)
        scan_matriz(iterador - 1, linhas, colunas, matriz);

    scanf("%d", &matriz[iterador / colunas][iterador % colunas]);
}
int count_row(int linha, int total_linhas, int coluna, int total_colunas, int matriz[total_linhas][total_colunas])
{
    if(linha >= total_linhas)
        return 0;
    return matriz[linha][coluna] + count_row(linha + 1, total_linhas, coluna, total_colunas, matriz);
}
void loop(int iterador, int linhas, int colunas, int matriz[linhas][colunas])
{
    if(iterador >= colunas) return;

    printf("Princesa %d: %d voto(s)\n", iterador + 1, count_row(0, linhas, iterador, colunas, matriz));
    loop(iterador + 1, linhas, colunas, matriz);
}
int main()
{
    int i, j;
    scanf("%d %d", &j, &i);
    int matriz[i][j];
    scan_matriz(i * j - 1, i, j, matriz);
    loop(0, i, j, matriz);
    return 0;
}