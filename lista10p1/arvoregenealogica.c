#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ZERO DEATHS

#define endl printf("\n")
#define cout(x) printf("%d", x)

#define INT_MAX 2147483647

typedef struct node
{
    int key;
    char* s;
    struct node *next;
} node_t;

node_t* create_node(int key, char* s)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->s = s;
    new_node->next = NULL;
    return new_node;
}

int pre_hash(node_t *head, char* s)
{
    node_t *current = head;

    while(1)
    {
        if(strcmp(current->s, s) == 0)
        {
            break;
        }
        if(current->next == NULL)
        {
            current->next = create_node(current->key + 1, s);
            current = current->next;
            break;
        }
        current = current->next;
    }
    return current->key;
}

void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("key %d: %s\n", current->key, current->s);
        current = current->next;
    }
}

void print_nome(node_t *head, int key0, int key1)
{
    node_t *current = head;

    char* s0, *s1;

    while (current != NULL)
    {
        if(current->key == key0)
        {
            s0 = current->s;
            break;
        }
        current = current->next;
    }

    current = head;
    while (current != NULL)
    {
        if(current->key == key1)
        {
            s1 = current->s;
            break;
        }
        current = current->next;
    }

    if(strcmp(s0, s1) > 0)
    {
        char* temp = s0;
        s0 = s1;
        s1 = temp;
    }
    printf("%s %s ", s0, s1);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int grau(int* gen_t, int father_key, int son_key)
{
    int father[100], son[100];
    int father_depth = 0, aux;
    aux = father_key;

   for(int i = 0; 1; i++)
    {   
        father[i] = aux;

        if(son_key == aux)
            return i;
        
        if(gen_t[aux] == 0)
            break;

        aux = gen_t[aux];

        father_depth++;
    }

    int son_depth = 0;
    aux = son_key;
   for(int i = 0; 1; i++)
    {   
        son[i] = aux;

        if(father_key == aux)
            return i;

        if(gen_t[aux] == 0)
            break;
        
        aux = gen_t[aux];

        son_depth++;
    }

    int equal_depth = 0;

    for(int i = 0; i < min(father_depth, son_depth); i++)
        if(father[father_depth - i] == son[son_depth - i])
            equal_depth++;

    if(equal_depth == 0)
        return -1;

    // printf("father_depth: %d, son_depth: %d, equal_depth: %d\n", father_depth, son_depth, equal_depth);

    return (father_depth - equal_depth) + (son_depth - equal_depth) + 2;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* gen_t = (int*)malloc(sizeof(int) * 2 * n);
    memset(gen_t, 0, sizeof(int) * 2 * n);

    node_t *head = (node_t*)malloc(sizeof(node_t));
    head->s = "SEN_PAI";
    head->key = 0;
    head->next = NULL;

    int son_key, father_key;

    char* s;
    for(int i = 0; i < n; i++)
    {
        // pai
        s = (char*)malloc(1000 * sizeof(char));

        scanf("%s", s);

        father_key = pre_hash(head, s);

        // filho

        s = (char*)malloc(1000 * sizeof(char));

        scanf("%s", s);

        son_key = pre_hash(head, s);

        gen_t[son_key] = father_key;
    }

    int max_dist = 0, dist = 0, sol[2], max_key;

    node_t* current = head;

    while(current->next != NULL)
    {
        current = current->next;
        max_key = current->key;
    }

    for(int i = 1; i < max_key + 1; i++)
    {
        for(int j = 1; j < max_key + 1; j++)
        {
            if(i == j)
                continue;
            
            dist = grau(gen_t, i, j);

            if(dist == -1)
            {
                print_nome(head, i, j);

                printf("%d", INT_MAX);
                endl;
                return 0;
            }
            
            if(dist > max_dist)
            {
                max_dist = dist;
                sol[0] = i;
                sol[1] = j;
            }
        }
    }

    print_nome(head, sol[1], sol[0]);

    printf("%d\n", max_dist);

    // printf("%d\n", grau(gen_t, 1, 10));
    // endl;

    return 0;
}