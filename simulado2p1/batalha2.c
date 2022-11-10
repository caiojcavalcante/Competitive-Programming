#include <stdio.h>

int scan(int a[], int n)
{
    if(n) scan(a, n - 1);
    scanf("%d", &a[n]);
}
void radix_sort(int a[], int n, int exp)
{
    int i, b[n], count[10] = {0};
    for(i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for(i = n - 1; i >= 0; i--)
    {
        b[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for(i = 0; i < n; i++)
        a[i] = b[i];
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int solve(int rodadas)
{
    if(rodadas == 0) return 0;
    int tamanho_pedro, tamanho_tulio;
    scanf("%d%d", &tamanho_pedro, &tamanho_tulio);
    int pedro[tamanho_pedro], tulio[tamanho_tulio];
    scan(pedro, tamanho_pedro - 1);
    scan(tulio, tamanho_tulio - 1);

    sort(pedro, 0, tamanho_pedro);
    sort(tulio, 0, tamanho_tulio);

    int maior_pedro = biggest(pedro, tamanho_pedro - 1);
    int maior_tulio = biggest(tulio, tamanho_tulio - 1);

    printf("pedro: %d ", maior_pedro);
    printf("tulio: %d\n", maior_tulio);
    return (maior_pedro > maior_tulio) + solve(rodadas - 1);
}
int main()
{
    int rodadas;
    scanf("%d", &rodadas);

    int vitorias_pedro = solve(rodadas);
    int vitorias_tulio = rodadas - vitorias_pedro;

    if(vitorias_pedro > vitorias_tulio)
        printf("Pedro foi vitorioso com %d pontos\n", vitorias_pedro);
    else if(vitorias_pedro < vitorias_tulio)
        printf("T�lio foi vitorioso com %d pontos\n", vitorias_tulio);
    else printf("T�lio e Pedro empataram com %d pontos\n", vitorias_pedro);
    
    return 0;
}