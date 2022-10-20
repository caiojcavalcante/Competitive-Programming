#include <stdio.h>

void print(int n)
{
    if(!n)
        return;
    print(n/10);
    printf("%c", n & 1 ? '.' : '-');
}
void solve()
{
    static int n;
    if(scanf("%d", &n) == EOF)
        return;
    print(n);
    printf("\n");
}
int main()
{
    solve();
    return 0;
}