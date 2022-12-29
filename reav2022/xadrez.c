#include <stdio.h>

void ataque_torre(int campo[8][8], int m[8][8], int x, int y)
{
    for(int i = x;i < 8; i++)
    {
        if(campo[i][y] < 3 && campo[i][y] > 0 && i != x)
            break;
        m[i][y] = 1;
    }
    for(int i = x;i >= 0; i--)
    {
        if(campo[i][y] < 3 && campo[i][y] > 0 && i != x)
            break;
        m[i][y] = 1;
    }
    for(int i = y;i < 8; i++)
    {
        if(campo[x][i] < 3 && campo[x][i] > 0 && y != i)
            break;
        m[x][i] = 1;
    }
    for(int i = y;i >= 0; i--)
    {
        if(campo[x][i] < 3 && campo[x][i] > 0 && y != i)
            break;
        m[x][i] = 1;
    }

}
void ataque_rei(int campo[8][8], int m[8][8], int x, int y)
{
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++)
            if(i >= 0 && i < 8 && j >= 0 && j < 8)
                m[i][j] = 1;
}

int main()
{
    int atacadas[8][8] = {0}, rei_x, rei_y, afogamento = 0, cheque = 0, aux;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            scanf("%d", &aux);

            if(aux == 1)
                ataque_torre(campo, atacadas, i, j);

            else if(aux == 2)
                ataque_rei(campo, atacadas, i, j);

            else if(aux == 3)
            {
                rei_x = i;
                rei_y = j;
            }
        }

    for(int i = rei_x - 1; i <= rei_x + 1; i++)
        for(int j = rei_y - 1; j <= rei_y + 1; j++)
            if(i < 0 || i >= 8 || j < 0 || j >= 8 || atacadas[i][j] == 1)
                afogamento++;

    if(atacadas[rei_x][rei_y] == 1)
        cheque = 1;

    if(afogamento == 9)
        printf("Xeque-mate\n");

    else if(afogamento == 8 && cheque == 0)
        printf("Afogado\n");

    else
        printf("Nao ocorreu ainda\n");

    // Descomente para ver a matriz de atacadas
    // for(int i = 0; i < 8; i++)
    // {
    //     for(int j = 0; j < 8; j++)
    //         printf("%d ", atacadas[i][j]);
    //     printf("\n");
    // }

    return 0;
}