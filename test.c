#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int fatorial(int z)
{
     if ( z == 0)
    {
        return 1;
    }
    else
    {
        return z * fatorial(z-1);
    }
}
int primo(int x, int cont)
{
    

    if(x == cont)
    {
        return x;
    }
    else if((x % cont == 0 && (cont != 1)) ||  x < 2)
    {
        return 0;
    }
    else
    {
        primo(x,cont + 1);
    }
}
int proximoprimo(int y)
{
    if(primo(y, 1) == y) 
    {
      return y;
    } 
    else 
    {
      return proximoprimo(y + 1);
    }
}
    
double serie(int n, int cont)
{
    
    if(n == cont )
    {
       return 0;
       
    }
    
    else 
    {
        if(n != 1)
            printf(" + ");
        printf("%d!/%d", n,proximoprimo(n));
        return (double)fatorial(n)/proximoprimo(n) + serie(n + 1, cont);
    }
}
int main() 
{
    int n;
    scanf("%d",&n);

    if (n == 0)
    {
        printf("0.00\n");
        return 0;
    }
    else if(n == 1)
    {
        printf("1!/1\n 1.00");
        return 0;
    }
    double resultado = serie(1,n);
    printf("\n%.2lf\n", resultado);

	return 0;
}