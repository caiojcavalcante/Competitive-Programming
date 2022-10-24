#include <stdio.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1
int main()
{
    int n, r, l, aux;

    scanf("%d", &n);

    int m[n][2];

    memset(m, -1, sizeof(m));

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &r, &l);
        m[i][RIGHT] = r;
        m[i][LEFT] = l;
    }

    for(int i = 1; i < n; i++)
    {
        //SOU UMA FOLHA
        if(m[i][LEFT] == -1 && m[i][RIGHT] == -1)
            continue;
        
        //SOU INTERMEDIARIO
        if(m[i][LEFT] != -1)
        {
            aux = m[i][LEFT];
            if(m[aux][LEFT] != -1 || m[aux][RIGHT] != -1)
                continue;
        }
        if(m[i][RIGHT] != -1)
        {
            aux = m[i][RIGHT];
            if(m[aux][RIGHT] != -1 || m[aux][LEFT] != -1)
                continue;
        }

        printf("%d\n", i);
    }
    return 0;
}