#include <stdio.h>

int main()
{
    int batalhas, m0[5][5], m1[5][5], s0, s1;
    char nome1[100], nome2[100];
    scanf("%d", &batalhas);
    for (int z = 0; z < batalhas; z++)
    {
        s0 = s1 = 0;
        scanf("%s", nome1);
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d", &m0[i][j]);

        scanf("%s", nome2);
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                scanf("%d", &m1[i][j]);

        for(int i = 0; i < 5; i++)
        {
            s0 += m0[i][i] + m0[i][4 - i];
            s1 += m1[i][i] + m1[i][4 - i];
        }
        
        if(s0 > s1)
            printf("%s venceu com valor %d\n", nome1, s0);
        else if(s0 < s1)
            printf("%s venceu com valor %d\n", nome2, s1);
        else
            printf("Empataram com o valor %d\n", s0);

    }
    return 0;
}