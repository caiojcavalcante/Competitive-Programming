#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int * primes = malloc(1000000 * sizeof(int));
    int n, target, min_mmc, mmc;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &target);
        min_mmc = target - 1;
        for(int j = 1; j < (target / 2) + 1; j++)
        {
            mmc = lcm(j, target - j);
            if(mmc < min_mmc)
                min_mmc = mmc;
        }
        printf("%d %d\n", target - min_mmc, min_mmc);
    }
    return 0;
}