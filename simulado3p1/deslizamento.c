#include <stdio.h>
#include <string.h>

int solve(int pos, int dir, int a[], int size, int ans[])
{
    if(pos == 0 && dir == -1) return 0;

    if(pos == size - 1 && dir == 1) return 0;

    if(pos != 0 && pos != (size - 1) && a[pos - dir] >= a[pos]) return 0;

    if(pos != 0 && pos != (size - 1)) ans[pos]++;

    return ans[pos] + solve(pos + dir, dir, a, size, ans);
}
int prnt_ans(int ans[], int size)
{
    if(size)
        prnt_ans(ans, size - 1);
    if(ans[size])
        printf("%d ", size);
}
void scan(int a[], int i)
{
    if(i) scan(a, i - 1);
    scanf("%d", &a[i]);
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], ans[n];
    scan(a, n - 1);

    memset(ans, 0, sizeof(ans));
    if(solve(0, 1, a, n, ans) == 0)
        printf("Nao ocorreu nenhum desabamento a esquerda");
    else
        printf("Desabamento a esquerda: ") && prnt_ans(ans, n - 1);

    endl

    memset(ans, 0, sizeof(ans));
    if(solve(n - 1, -1, a, n, ans) == 0)
        printf("Nao ocorreu nenhum desabamento a direita");
    else
        printf("Desabamento a direita: ") && prnt_ans(ans, n - 1);

    return 0;
}