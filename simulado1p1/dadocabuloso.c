#include <stdio.h>

int is_prime(int a, int b)
{ 
    if(a == 1)
        return 0;
    if(b * b > a)
        return 1;
    if(!(a % b))
        return 0;
    return is_prime(a, b + 1);
}
int soma_digitos(n)
{
    return n ? n % 10 + soma_digitos(n / 10) : 0;
}
int proximo_primo(int a)
{
    if(is_prime(a, 2))
        return a;
    return proximo_primo(a + 1);
}
int mdc(int a, int b)
{
    return b ? mdc(b, a % b) : a;
}
void swap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
void sort(int a[], int i, int size)
{
    if(size <= 0)
        return;
 
    if(i >= size)
        return sort(a, 0, size - 1);

    if(a[i] > a[i + 1])
        swap(&a[i], &a[i + 1]);
 
    sort(a, i + 1, size);
}
int pontos(int maior, int fator_principal)
{
    return (is_prime(fator_principal, 2)) + (mdc(maior, fator_principal) == 1) + (is_prime(soma_digitos(proximo_primo(fator_principal + 1)), 2));
}
int scan(int kcaj[], int ordep[], int jogadas)
{
    if (jogadas < 0) return 0;

    scanf("%d", &kcaj[jogadas]);
    scanf("%d", &ordep[jogadas]);

    if(kcaj[jogadas] > 1500 || kcaj[jogadas] < 0 || ordep[jogadas] > 1500 || ordep[jogadas] < 0)
    {
        printf("valor fora do limite!\n");
        return -1;
    }

    return scan(kcaj, ordep, jogadas - 1);
}
void solve(int rodadas, int jogadas)
{
    int kcaj[jogadas], ordep[jogadas];

    int pontos_kcaj, principal_kcaj, pontos_ordep, principal_ordep;

    if (scan(kcaj, ordep, jogadas - 1) != 0 && rodadas > 0)
        return solve(rodadas - 1, jogadas);

    sort(kcaj, 0, jogadas);
    sort(ordep, 0, jogadas);

    printf("scanedo\n");
    for(int i = 0; i < jogadas; i++)
    {
        printf("j%d\n", kcaj[i]);
    }
    for(int i = 0; i < jogadas; i++)
    {
        printf("p%d\n", ordep[i]);
    }

    principal_kcaj = kcaj[0]  + kcaj[(jogadas)  / 2] + kcaj[jogadas - 1];
    principal_ordep = ordep[0] + ordep[(jogadas) / 2] + ordep[jogadas - 1];

    pontos_kcaj  = pontos(kcaj[jogadas - 1], principal_kcaj);
    pontos_ordep = pontos(ordep[jogadas - 1], principal_ordep);

    printf("kcaj:%d ordep: %d\n", pontos_kcaj, pontos_kcaj);

    if(pontos_kcaj > pontos_ordep)
        printf("Kcaj %d\n\n", principal_kcaj);

    else if(pontos_kcaj > pontos_ordep)
        printf("Ordep %d\n\n", principal_ordep);

    else
        printf("empate\n\n");

    if(rodadas)
        solve(rodadas - 1, jogadas);
}
int main()
{
    int rodadas, jogadas;
    scanf("%d%d", &rodadas, &jogadas);
    solve(rodadas - 1, jogadas);
    return 0;
}