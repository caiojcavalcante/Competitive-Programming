#include <stdio.h>

int main()
{
    int n, m[9][9], numeros[9];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Instancia %d\n", i + 1);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d ", &m[i][j]);
        int ans = 1;
        for (int i = 0; i < 9; i++)
        {
            memset(numeros, 0, sizeof(numeros));
            int linha = 0;
            for (int j = 0; j < 9; j++)
            {
                if(numeros[m[i][j] - 1])
                    ans = 0;
                linha += m[i][j];
                numeros[m[i][j] - 1]++;
            }
                
            if (linha != 45)
                ans = 0;
        }
        for (int i = 0; i < 9; i++)
        {
            memset(numeros, 0, sizeof(numeros));
            int coluna = 0;
            for (int j = 0; j < 9; j++)
            {
                if(numeros[m[j][i] - 1])
                    ans = 0;
                coluna += m[j][i];
                numeros[m[j][i] - 1]++;
            }

            if (coluna != 45)
                ans = 0;
        }
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                memset(numeros, 0, sizeof(numeros));
                int quadrado = 0;
                for(int k = 0; k < 3; k++)
                    for(int l = 0; l < 3; l++)
                    {
                        quadrado += m[i + k][j + l];
                        if(numeros[m[i + k][j + l] - 1])
                            ans = 0;
                        numeros[m[i + k][j + l] - 1]++;
                    }

                if(quadrado != 45) ans = 0;
            }
        }
        printf("%s\n\n", ans ? "SIM" : "NAO");
    }
    return 0;
}