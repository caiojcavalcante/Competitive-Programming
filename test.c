#include <stdio.h> 
#include <math.h>

void dedicado (int contador, int total_programas, int total_linhas,int max_linhas, int dia_max_linhas)
{
    if (contador==7)
    {
        printf ("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", total_programas); 
        printf ("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n",total_linhas); 
        printf ("DIA QUE MAIS PRODUZIU: ");
        if (dia_max_linhas == 1)
        {
            printf ("DOMINGO");
        }
        else if (dia_max_linhas == 2)
        {
            printf ("SEGUNDA");
        }   
        else if (dia_max_linhas == 3)
        {
            printf ("TERCA");
        }
        else if (dia_max_linhas == 4)
        {
            printf ("QUARTA");
        }
        else if (dia_max_linhas == 5)
        {
            printf ("QUINTA");
        }
        else if (dia_max_linhas == 6)
        {
            printf ("SEXTA");
        }
        else if (dia_max_linhas == 7)
        {
            printf ("SABADO");
        }
        return;
    }

    int programas , linhas;  
    scanf ("%d%d",&programas, &linhas);
    contador += 1; 
    if (linhas > max_linhas)
    {
        max_linhas = linhas; 
        dia_max_linhas = contador;
    }
    if (programas >=5)
    {
        total_programas += 1; 
    }

    if (linhas>=100)
    {
        total_linhas +=1; 
    }
    dedicado(contador,total_programas, total_linhas,max_linhas, dia_max_linhas); 
}

    int main ()
{
        dedicado(0,0,0,0,0); 
    return 0; 
}