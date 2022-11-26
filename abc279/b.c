#include <stdio.h>

int main()
{
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);

    for(int i = 0; i < 101; i++)
    {
        if(s[i] == '\0')
        {
            printf("No\n");
            return 0;
        }
        for(int j = 0; j < 101; j++)
        {
            if(t[j] == '\0')
            {
                printf("Yes\n");
                return 0;
            }
            if(s[i + j] != t[j])
                break;
        }
    }
    return 0;
}