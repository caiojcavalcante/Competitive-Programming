#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
} Pilha;

Pilha *push(Pilha *pilha)
{
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->next = pilha;
    return novo;
}

Pilha *pop(Pilha *pilha)
{
    return pilha->next;
}

int main()
{
    int n; // numero de casos de teste
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        Pilha *parenteses = NULL;
        Pilha *chave = NULL;
        char buffer;
        short flag = 1;
        while (1)
        {
            buffer = getchar();

            if (buffer == '\n' || buffer == EOF)
                break;

            if (buffer == '(')
                parenteses = push(parenteses);

            if (buffer == ')')
            {
                if (parenteses == NULL)
                {
                    flag = 0;
                }
                else
                    parenteses = pop(parenteses);
            }
            if (buffer == '[')
                chave = push(chave);

            if (buffer == ']')
            {
                if (chave == NULL)
                {
                    flag = 0;
                }
                else
                    chave = pop(chave);
            }
        }
        if(parenteses != NULL || chave != NULL)
            flag = 0;
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}