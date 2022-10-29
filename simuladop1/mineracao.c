#include <stdio.h>

int solve(int a[], int buraco)
{
    if(a[a[buraco]] == -1)
        return a[buraco];
    return solve(a, a[buraco]);
}
void scan(int a[], int i)
{
    if(i) scan(a, i - 1);
    scanf("%d", &a[i]);
}
int main()
{
    int buracos, entrada;
    scanf("%d", &buracos);

    int a[buracos];
    scan(a, buracos - 1);

    scanf("%d", &entrada);

    printf("%d", solve(a, entrada));
    return 0;
}