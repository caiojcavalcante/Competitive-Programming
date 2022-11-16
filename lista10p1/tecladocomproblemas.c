#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define endl printf("\n")

typedef struct node
{
    char *s;
    struct node *next;
} node_t;

void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%s", current->s);
        current = current->next;
    }
}

node_t *create_node(char *s)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->s = s;
    new_node->next = NULL;
    return new_node;
}

void shift(node_t **head, char *s)
{
    node_t *new_node = create_node(s);
    new_node->next = *head;
    *head = new_node;
}

void push(node_t **tail, char *s)
{
    (*tail)->next = create_node(s);
    *tail = (*tail)->next;
}

int main()
{
    char* str = (char*)malloc(100005 * sizeof(char));

    while(scanf("%s", str) != EOF)
    {
        node_t *head = create_node("");

        node_t *tail = create_node("");

        head->next = tail;

        int len = strlen(str);

        char state = '[', temp;

        int j = 0, stop = 0;
        for (int i = 0; 1; i++)
        {
            temp = str[i];

            if(str[i] == '[' || str[i] == ']' || str[i] == '\0')
            {
                str[i] = '\0';

                if(state == '[')
                    shift(&head, str + j);
                else
                    push(&tail, str + j);

                state = temp;
                j = i + 1;
            }
            if(state == '\0')
                break;
        }
        print_list(head);
        endl;
    }

    return 0;
}