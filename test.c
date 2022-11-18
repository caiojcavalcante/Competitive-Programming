#include <stdio.h>
#include <stdlib.h>

#define cout(x) printf("%d", x)
#define endl printf("\n")
#define PRINTARRAY(array, length) for (int i = 0; i < length; i++) printf("%d ", array[i]);
#define SCANARRAY(array, length) for (int i = 0; i < length; i++) scanf("%d", &array[i]);

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

node* create_node(int val)
{
    node *new_node = malloc(sizeof(node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int val)
{
    node* current = root;
    while(current != NULL)
    {
        if(val < current->val)
        {
            if(current->left == NULL)
            {
                current->left = create_node(val);
                break;
            }
            current = current->left;
        }
        if(val > current->val)
        {
            if(current->right == NULL)
            {
                current->right = create_node(val);
                break;
            }
            current = current->right;
        }
        if(val == current->val)
        {
            break;
        }
    }
}

void in_order(node* root)
{
    if(root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->val);
        in_order(root->right);
    }
}

int main()
{
    int a[10] = {34, 12, 56, 7, 23, 45, 78, 1, 9, 3};

    node* root = malloc(sizeof(node));
    root->val = a[0];

    for(int i = 1; i < 10; i++)
    {
        insert(root, a[i]);
    }

    in_order(root);

    endl;

    return 0;
}