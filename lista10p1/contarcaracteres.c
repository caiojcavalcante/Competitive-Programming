#include <stdio.h>
#include <string.h>

int main()
{
    char s[81], c, fim[15] = "NAO QUERO MAIS";

    while(1)
    {
        for(int i = 0; 1; i++)
        {
            c = getchar();

            if(c == '\n'|| c == EOF)
            {
                s[i] = '\0';
                break;
            }

            s[i] = c;
        }

        printf("%s\n", s);
    }

    return 0;
}