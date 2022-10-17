#include <stdio.h>

int solve(int *infratores)
{
    int carros;
    scanf("%d", &carros);
    if(carros == 999)
        return 0;
    *infratores += carros > 2;
    return (carros - 2) * (carros > 2) + solve();
}
int main()
{
    int infratores;
    int ans = solve(&infratores);
    printf("%.2lf\n%d", ans * 12.89, ans);
    return 0;
}