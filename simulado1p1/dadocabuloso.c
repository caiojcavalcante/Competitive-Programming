#include <stdio.h>

int is_prime(int n, int div)
{
    if(n < 2)
        return 0;
    if(div * div > n)
        return 1;
    if(n % div == 0)
        return 0;
    return is_prime(n, div + 1);
}
int proximo_primo(int n)
{
    if(is_prime(n, 2))
        return n;
    return proximo_primo(n + 1);
}
int soma_digitos(int n)
{
    if(n == 0)
        return 0;
    return (n % 10) + soma_digitos(n / 10);
}
int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}
void sort(int a[], int i, int size)
{
    if(size == 0)
        return;
    if(i == size)
        return sort(a, 0, size - 1);
    if(a[i] > a[i + 1])
    {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    sort(a, i + 1, size);
    
}
int pontos(int fator, int maior)
{
    return (is_prime(fator, 2)) + (mdc(fator, maior) == 1) + (is_prime(soma_digitos(proximo_primo(fator + 1)), 2));
}
int scan(int ordep[], int kcaj[], int jogadas)
{
    if(jogadas < 0) return 0;
    int dado, valido = 0;

    scanf("%d", &dado);
    if(dado > 1500 || dado <= 0) valido++;
    ordep[jogadas] = dado;
    scanf("%d", &dado);
    if(dado > 1500 || dado <= 0) valido++;
    kcaj[jogadas] = dado;

    return valido + scan(ordep, kcaj, jogadas - 1);    
}
void solve()
{
    int jogadas, fator_kcaj, fator_ordep, pontos_kcaj, pontos_ordep, valido;
    scanf("%d", &jogadas);
    int ordep[jogadas], kcaj[jogadas];

    valido = !scan(ordep, kcaj, jogadas - 1);
        
    sort(ordep, 0, jogadas - 1);
    sort(kcaj, 0, jogadas - 1);

    fator_kcaj = kcaj[0] + kcaj[jogadas - 1] + kcaj[jogadas / 2];
    fator_ordep = ordep[0] + ordep[jogadas - 1] + ordep[jogadas / 2];

    pontos_kcaj = pontos(fator_kcaj, kcaj[jogadas - 1]);
    pontos_ordep = pontos(fator_ordep, ordep[jogadas - 1]);
    
    if(valido)
    {
        if(pontos_kcaj > pontos_ordep)
            printf("Kcaj %d\n", fator_kcaj);
        else if(pontos_kcaj < pontos_ordep)
            printf("Ordep %d\n", fator_ordep);
        else
            printf("empate\n");
    }
    else
        printf("valor fora do limite!\n");
}
void loop(int rodadas)
{
    solve();
    if(rodadas) loop(rodadas - 1);
}
int main()
{
    int rodadas;
    scanf("%d", &rodadas);
    loop(rodadas - 1);
    return 0;
}