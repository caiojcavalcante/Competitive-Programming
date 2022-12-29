#include <stdio.h>

int main()
{
    int n, f = 1;
    for(int i = 0;i < 8;i++)
    {
        scanf("%d", &n);
        if(n > 1)
        {
            f = 0;
            break;
        }
    }
    printf("%c\n", f ? 'S' : 'F');
}