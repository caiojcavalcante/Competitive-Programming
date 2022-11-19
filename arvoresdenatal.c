#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char a[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = '-';
    }
    a[n / 2] = '*';
    for(int j = 0; j < 1 + (n / 2); j++)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%c", a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i + 1] == '*')
                a[i] = '*';
            if(a[i] == '*' && a[i + 1] != '*')
            {
                a[i + 1] = '*';
                break;
            }
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = '-';
    }
    a[n / 2] = '*';
    for(int j = 0; 1 + 2 * j < (n / 2) + 1; j++)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%c", a[i]);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i - 1] == '*')
                a[i] = '*';
            if(a[i] == '*' && a[i - 1] != '*')
            {
                a[i - 1] = '*';
                break;
            }
        }
        printf("\n");
    }

    return 0;
}