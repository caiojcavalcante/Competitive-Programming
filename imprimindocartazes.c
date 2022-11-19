#include <stdio.h>
#include <string.h>

int main()
{
    int cor, len, grafica;
    char s[201];
    scanf("%d%s", &cor, s);
    len = strlen(s);

    double preco1, preco2;
    double precoinicial1, precoinicial2;

    if(len < 11)
    {
        precoinicial1 = 0;
        precoinicial2 = 0;
        preco1 = .75;
        preco2 = .25;
    }
    else if(len < 31)
    {
        precoinicial1 = 7.5;
        precoinicial2 = 2.5;
        len -= 10;
        preco1 = 0.45;
        preco2 = 0.15;
    }
    else
    {
        precoinicial1 = 16.5;
        precoinicial2 = 5.5;
        len -= 30;
        preco1 = 0.2;
        preco2 = 0.1;
    }

    if((preco1 * len + (cor == 1 ? 2 : 4) + precoinicial1) > (preco2 * len + (cor == 1 ? 6 : 9) + precoinicial2))
        grafica = 1;
    else
        grafica = 2;

    printf("A grafica %d eh a mais em conta\nO preco sera: $%.2lf", grafica, grafica == 1 ? (preco1 * len + (cor == 1 ? 2 : 4) + precoinicial1) : (preco2 * len + (cor == 1 ? 6 : 9) + precoinicial2));

    return 0;
}