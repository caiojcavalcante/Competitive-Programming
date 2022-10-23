#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret, dias, i = 1, frutas = 0, total_frutas = 0;
    double preco, preco_total = 0;
    char s[100];
    scanf("%d", &dias);
    while(i <= dias)
    {
        if(scanf("%s", &s) == EOF) 
        {
            printf("dia %d: %d kg\n", i, frutas);
            break;
        }
        preco = atof(s);
        preco_total += preco;
        if(preco == 0)  
            frutas++;
        else if (frutas)
        {
            printf("dia %d: %d kg\n", i, frutas);
            total_frutas += frutas;
            frutas = 0;
            i++;
        }
    }
    printf("%.2lf kg por dia\n", total_frutas / (double)dias);
    printf("R$ %.2lf por dia\n", preco_total / (double)dias);
}