#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

void print(node_t* no)
{
    while(no != NULL)
    {
        printf("%d ", no->data);
        no = no->next;
    }
}

node_t* add(int data, node_t* list)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list;
    return new_node;
}

int main()
{
    node_t* head = NULL;

    head = add(5, head);
    head = add(2, head);
    head = add(4, head);
    head = add(1, head);

    print(head);

    return 0;
}