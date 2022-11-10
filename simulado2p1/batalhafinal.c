#include <stdio.h>
#include <string.h>

void scan(int a[], int b[], int n)
{
    if(n) scan(a, b, n - 1);
    int aux;
    scanf("%d", &aux);
    a[n] = aux;
    b[aux]++;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int biggest(int a[], int frq[], int n, int maior, int *indice)
{
    if(n == 0) return a[0];
    if(frq[a[0]] > maior) 
    {
        maior = frq[a[0]];
        *indice = n;
    }
    return biggest(a, frq, n - 1, maior, indice);
}
int solve(int rodadas)
{
    if(rodadas == 0) return 0;
    int pedro_freq[100000], tulio_freq[100000];
    int tamanho_pedro, tamanho_tulio;

    memset(pedro_freq, 0, sizeof(pedro_freq));
    memset(tulio_freq, 0, sizeof(tulio_freq));

    scanf("%d%d", &tamanho_pedro, &tamanho_tulio);
    int pedro[tamanho_pedro], tulio[tamanho_tulio];
    scan(pedro, pedro_freq, tamanho_pedro - 1);
    scan(tulio, tulio_freq, tamanho_tulio - 1);

    int maior_pedro, maior_tulio;
    biggest(pedro, pedro_freq, tamanho_pedro - 1, 0, &maior_pedro);
    biggest(tulio, tulio_freq, tamanho_tulio - 1, 0, &maior_tulio);

    printf("pedro: %d ", pedro[maior_pedro]);
    printf("tulio: %d\n", tulio[maior_tulio]);
    return (pedro[maior_pedro] > tulio[maior_tulio]) + solve(rodadas - 1);
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
        printf("Túlio foi vitorioso com %d pontos\n", vitorias_tulio);
    else printf("Túlio e Pedro empataram com %d pontos\n", vitorias_pedro);

    return 0;
}