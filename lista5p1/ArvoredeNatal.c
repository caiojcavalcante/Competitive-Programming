#include <stdio.h>

float solve()
{
    float enfeite, qntd;
    if(scanf("%f %f", &enfeite, &qntd) == EOF) return 0;
    return enfeite * qntd + solve();
}
int main()
{
    float arvore;
    scanf("%f", &arvore);
    float ans = arvore + solve()
    printf("%.2f\n%.2f\n", ans, ans / 21);
    return 0;
}