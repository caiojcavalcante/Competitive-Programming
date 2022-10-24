#include <stdio.h>
#include <string.h>

#define RIGHT 1
#define LEFT 0

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* create_node(int data)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* create_tree(int root, int size, int m[][2])
{   
    node* root = NULL;
    for (size--)
    {
        root = create_node(r);

        if(m[size][LEFT] != -1)
            root->left = create_node(m[size][LEFT]);
        if(m[size][RIGHT] != -1)
            root->right = create_node(m[size][RIGHT]);
        
    }
}

int main()
{
    int n, k, r, aux;
    scanf("%d %d %d", &n, &k, &r);

    // Node* tree = (Node*) malloc(sizeof(Node))

    node *tree = (node *)malloc(sizeof(node));

    int m[n][2];

    memset(m, -1, sizeof(m));
    
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &aux);
        scanf("%d%d", &m[aux][0], &m[aux][1]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", m[i][0], m[i][1]);
    }

    create_tree(r, n, m);

    return 0;
}