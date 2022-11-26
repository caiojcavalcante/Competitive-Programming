#include <stdio.h>

int main()
{
    char c;
    int ans = 0;
    while(scanf(" %c", &c) != EOF)
    {
        if(c == 'w')
            ans++;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}