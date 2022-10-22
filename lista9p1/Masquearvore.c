#include <stdio.h>
#include <string.h>

// struct Node
// {
//     int valor;
//     struct Node* esquerda;
//     struct Node* direita;
// };
// void create_node(struct Node* node, int valor)
// {
//     node->valor = valor;
//     node->esquerda = NULL;
//     node->direita = NULL;
// }
// void create_tree(struct Node* node)
// {
//     int valor;
//     struct Node* novo_node = (struct Node*) malloc(sizeof(struct Node));
//     while(1)
//     {
//         if(scanf("%d", &valor) == EOF) return;

//         if(valor == -1)
//             novo_node = novo_node->esquerda;

//         if(novo_node->esquerda == NULL)
//             create_node(novo_node->esquerda, valor);

//         if(novo_node->direita == NULL)
//             create_node(novo_node->direita, valor);
        
//         if(valor == novo_node->esquerda)
//             novo_node = novo_node->esquerda;
//         else
//             novo_node = novo_node->direita;
//     }
// }
int main()
{
    int n, k, r, aux;
    scanf("%d %d %d", &n, &k, &r);

    // Node* tree = (Node*) malloc(sizeof(Node))

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

    return 0;
}