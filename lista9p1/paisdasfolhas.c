#include <stdio.h>

int main()
{
    int n, r, l;
    scanf("%d", &n);
    scanf("%d%d");
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &r, &l);
        if(r != -1 || l != -1)
            printf("%d\n", i);
    }
    return 0;
}