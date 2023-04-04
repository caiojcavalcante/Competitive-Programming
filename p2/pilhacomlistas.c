#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} List;

typedef struct stack
{
    struct list *top;
    struct stack *next;
} Stack;

Stack *push(Stack *stack, List *list)
{
    Stack *new_list = (Stack *)malloc(sizeof(Stack));
    new_list->top = list;
    new_list->next = stack;
    return new_list;
}

List *pop(Stack **stack)
{
    if (*stack == NULL)
        return NULL;
    List *list = (*stack)->top;
    *stack = (*stack)->next;
    return list;
}

int main()
{
    Stack *p = NULL;
    int buffer;
    char command[5];
    while (1)
    {
        List *aux;
        if (scanf("%s", command) == EOF)
            break;
        if (command[1] == 'U')
        {

            List *list = (List *)malloc(sizeof(List));
            aux = list;
            while (1)
            {
                scanf("%d", &buffer);
                command[4] = getchar();
                aux->data = buffer;
                aux->next = (List *)malloc(sizeof(List));
                aux = aux->next;
                if (command[4] == '\n' || command[4] == EOF)
                    break;
            }
            p = push(p, list);
        }

        if (command[1] == 'O')
        {
            aux = pop(&p);
            if (aux != NULL)
            {
                while (aux->next != NULL)
                {
                    printf("%d", aux->data);
                    aux = aux->next;
                    if (aux->next != NULL)
                        printf(" ");
                }
                printf("\n");
            }
            else
                printf("EMPTY STACK\n");
        }
    }
}