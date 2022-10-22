#include <stdio.h>

int fatorial(int n)
{
    return n <= 1 ? 1 : n * fatorial(n - 1);
}
int somaDigitos(int n)
{
    return n ? n % 10 + somaDigitos(n / 10) : 0;
}
int mdc(int a, int b)
{
    return b ? mdc(b, a % b) : a;
}
int isPrime(int n, int div)
{
    if(n > 1 && div * div > n)
        return 1;

    return (n > 1 && n % div) ? isPrime(n, div + 1) : 0;
}
void solve(int dia, int dias_totais, double total_kcaj, double total_ordep, int kcaj_producao, int ordep_producao)
{
    if(dia > dias_totais)
    {
        if(total_kcaj > total_ordep)
            printf("Kcaj Ganhou!\n%.2lf", total_kcaj);
        else
            printf("Ordep Ganhou!\n%.2lf", total_ordep);
        return;
    }
    total_kcaj += kcaj_producao;
    total_ordep += ordep_producao;
    //KCAJ
    if(isPrime(dia, 2))
        total_kcaj += kcaj_producao * 5 / 100.;

    if(isPrime(somaDigitos(fatorial(dia)), 2))
    {
        total_kcaj += total_ordep / 10.;
        total_ordep -= total_ordep / 10.;
    }
    //ORDEP
    if(!(ordep_producao % somaDigitos(fatorial(dia))))
        total_ordep += 30;

    if(mdc(dia > ordep_producao ? ordep_producao : dia, dia < ordep_producao ? ordep_producao : dia) == 1)
    {
        total_ordep += total_kcaj / 10.;
        total_kcaj -= total_kcaj / 10.;
    }
    solve(dia + 1, dias_totais, total_kcaj, total_ordep, kcaj_producao, ordep_producao);
}
int main()
{
    int dias, kcaj_producao, ordep_producao;
    scanf("%d", &dias);
    scanf("%d%d", &kcaj_producao, &ordep_producao);
    solve(1, dias, 0, 0, kcaj_producao, ordep_producao);
}