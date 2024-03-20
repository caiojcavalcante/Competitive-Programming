#include <stdio.h>

int soma(int x, int y)
{
    // Complete a função para que
    // ela retorne a soma de x e y
    return x + y;
}

float media(int x, int y)
{
    // Complete a função para que
    // ela retorne a media de x e y
    return (x + y) / 2;
}

int maior(int x, int y)
{
    // Complete a função para que
    // retorne o maior numero entre x e y
    int m;
    if (x > y)
    {
        m = x;
    }
    else
    {
        m = y;
    }
    return m;
}

// = atribuir
// == comparar

int fatorial(int n)
{
    // Complete a função para que retorne
    // o fatorial de N
    if(n == 0)
    {
        return 1;
    }
    return n * fatorial(n - 1);
}

int primo(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for(int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
    // Complete a função para que retorne
    // 0 - caso o numero não seja primo
    // 1 - caso o numero seja primo
}

int main()
{
    // // //questao 1 - soma
    // int a, b;

    // printf("Digite um numero: ");

    // scanf("%d", &a);

    // printf("Digite mais um numero: ");
    // scanf("%d", &b);

    // int num = soma(a, b);

    // printf("A soma e: %d\n", num);

    // //questao 2 - media
    // float m = media(a, b);

    // printf("A media dos numeros e: %.2f\n", m);

    // questao 3 - maior

    // int num = maior(a, b);

    // printf("O maior numero e: %d\n", num);

    // //questao 4 - fatorial
    int num;
    printf("Digite um numero para calcular o fatorial: ");

    scanf("%d", &num);

    printf("O fatorial de %d e: %d\n", num, fatorial(num));

    // //questao 5 - primo
    // printf("Digite um numero para verificar se e primo: ");

    // scanf("%d", &num);

    // if (primo(num))
    // {
    //     printf("%d e primo\n", num);
    // }
    // else
    // {
    //     printf("%d nao e primo\n", num);
    // }

    return 0;
}