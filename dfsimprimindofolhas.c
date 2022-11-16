#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define endl printf("\n")
#define cout(x) printf("%d", x)

typedef struct adj_list
{
    int key;
    struct adj_list *next;
} adj_list;

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

adj_list* create_adj_list(int key)
{
    adj_list *new_adj_list = malloc(sizeof(adj_list));
    new_adj_list->key = key;
    new_adj_list->next = NULL;
    return new_adj_list;
}

int pre_hash(node_t** head, char* s)
{
    node_t *current = *head;
    int lexico;
    while(1)
    {
        lexico = strcmp(current->s, s);
        printf("lexico: %d\n", lexico);
        if(lexico == 0)
            break;

        if(lexico > 0)
        {
            printf("%s > %s\n", current->s, s);
            *head = create_node(current->key, s);
            
            printf("head: %s\n", (*head)->s);
            printf("current: %s\n", current->s);

            (*head)->next = current;
            while(current->next != NULL)
            {
                current->next->key++;
                current = current->next;
            }
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

int main()
{
    // node_t *head = create_node(0, "a");
    // head->adj_list = create_adj_list(1);
    // head->adj_list->next = create_adj_list(2);

    node_t * head = create_node(0, "ART9");
    
    pre_hash(&head, "ART10");
    pre_hash(&head, "ART11");
    pre_hash(&head, "QUI3");
    pre_hash(&head, "ART2");

    while(head != NULL)
    {
        printf("key %d: %s\n", head->key, head->s);
        head = head->next;
    }

    
    return 0;
}