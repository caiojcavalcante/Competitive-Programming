    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    typedef struct lista
    {
        int data;
        struct lista *prox;
    } lista_t;

    int find(lista_t *l, int data)
    {
        if (l == NULL)
            return 0;

        if (l->data == data)
            return 1;

        return find(l->prox, data);
    }

    void insert(lista_t *l, int data)
    {
        if (l->data == data)
            return;

        if (l->prox == NULL)
        {
            l->prox = (lista_t *)malloc(sizeof(lista_t));
            l->prox->data = data;
            l->prox->prox = NULL;
            return;
        }

        insert(l->prox, data);
    }

    void print(lista_t *l)
    {
        if (l == NULL)
            return;

        printf("%d ", l->data);
        print(l->prox);
    }

    int main()
    {
        int intersecao = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        int buffer;
        lista_t *lista = (lista_t *)malloc(sizeof(lista_t));
        lista_t *res = (lista_t *)malloc(sizeof(lista_t));


        for (int i = 0; i < 20; i++)
        {
            scanf("%d", &buffer);
            insert(lista, buffer);
        }

        for (int i = 0; i < 20; i++)
        {
            scanf(" %d", &buffer);
            if (find(lista, buffer) && !find(res, buffer))
            {
                if(buffer > max)
                    max = buffer;
                if(buffer < min)
                    min = buffer;

                insert(res, buffer);
                intersecao++;
            }
        }

        if (!intersecao)
            printf("VAZIO");

        for(int i = min - 1; i <= max; i++)
            if(find(res, i))
                printf("%d\n", i);

        return 0;
    }