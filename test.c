#include <stdio.h>

int eh_primo(int n, int div)
{
    if (div * div > n)
        return 1;
    if (n % div == 0)
        return 0;
    return eh_primo(n, div + 1);
}
int proximo_primo(int n)
{
    return eh_primo(n) ? n : proximo_primo(n + 1);
}
int fatorial(int n)
{
    return n <= 1 ? 1 : fatorial(n - 1) * n;
}
double loop(int n)
{
    if (n)
    {
        double acc = loop(n - 1);
        printf("%s%d!/%d", (n - 1) ? " + " : "", n, proximo_primo(n));
        return acc + (double)fatorial(n) / proximo_primo(n);
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    printf("\n%.2lf", loop(n));

    return 0;
}