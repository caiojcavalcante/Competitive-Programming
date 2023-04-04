#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int data;
    struct lista *prox;
} lista_t;

typedef struct num
{
    int length;
    lista_t *head;
} num;

void read(num *n)
{
    char buffer;
    scanf(" %c", &buffer);
    if (buffer == '+' || buffer == '=')
        return;

    n->head = (lista_t *)malloc(sizeof(lista_t));
    n->head->data = buffer - '0';
    n->length = 1;

    lista_t *aux = n->head;

    while (scanf(" %c", &buffer) && buffer != '+' && buffer != '=')
    {
        aux->prox = (lista_t *)malloc(sizeof(lista_t));
        aux = aux->prox;
        aux->data = buffer - '0';
        n->length++;
    }
}

void print(num *n)
{
    lista_t *aux = n->head;
    for (int i = 0; i < n->length; i++)
    {
        if (i)
            printf(" ");
        printf("%d", aux->data);
        aux = aux->prox;
    }
}

int sum_list(lista_t *a, lista_t *b, lista_t *res)
{
    if (a == NULL || b == NULL || res == NULL)
        return 0;

    res->prox = (lista_t *)malloc(sizeof(lista_t));

    res->data = a->data + b->data + sum_list(a->prox, b->prox, res->prox);

    int carry = res->data / 10;

    res->data %= 10;

    return carry;
}

int _max(int a, int b)
{
    return a > b ? a : b;
}

num *sum(num *a, num *b)
{
    while (a->length < b->length)
    {
        lista_t *aux = (lista_t *)malloc(sizeof(lista_t));
        aux->data = 0;
        aux->prox = a->head;
        a->head = aux;
        a->length++;
    }
    while (a->length > b->length)
    {
        lista_t *aux = (lista_t *)malloc(sizeof(lista_t));
        aux->data = 0;
        aux->prox = b->head;
        b->head = aux;
        b->length++;
    }
    num *res = (num *)malloc(sizeof(num));
    res->head = (lista_t *)malloc(sizeof(lista_t));
    res->length = _max(a->length, b->length);

    int carry = sum_list(a->head, b->head, res->head);

    if (carry)
    {
        lista_t *aux = (lista_t *)malloc(sizeof(lista_t));
        aux->data = carry;
        aux->prox = res->head;
        res->head = aux;
        res->length++;
    }

    while (res->head->data == 0 && res->head->prox != NULL)
    {
        res->head = res->head->prox;
        res->length--;
    }

    if (res->length == 0)
        printf("Lista vazia!");
        
    else
        print(res);
}

int main()
{
    num *a = (num *)malloc(sizeof(num));
    num *b = (num *)malloc(sizeof(num));

    read(a);
    read(b);

    sum(a, b);

    return 0;
}