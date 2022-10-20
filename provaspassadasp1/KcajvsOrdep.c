#include <stdio.h>
//0 deaths club
#define true 1
#define false 0
typedef bool int;

bool isPrime(int n, int div)
{
    if (div * div > n)
        return true;
    if (n % div == 0)
        return false;
    return isPrime(n, div + 1);
}

int fibonacci(int n)
{
    return n == 0 ? 1 : (n == 1 ? 1 : fibonacci(n - 2) + fibonacci(n - 1));
}

void rodada(int rodadas)
{
    if(rodadas)
    {
        int a, b;
        scanf("%d %d", &a, &b);

    }
}
int main()
{
    int rodadas;
    scanf("%d", &rodadas);
    round(rodadas);
}