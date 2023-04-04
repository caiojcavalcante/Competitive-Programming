#include <stdio.h>
#include <string.h>

typedef struct node
{
    char data;
    int freq;
    struct node *next;
} node_t;

typedef struct arvore
{
    int chave;
    struct arvore *left;
    struct arvore *right;
} Arvore;

Arvore *busca(Arvore *no, int num)
{
    if (no == NULL || no->chave == num)
        return no; // os dois primeiros if sao iguais, ent so colocar OR

    if (no->chave > num)
        return busca(no->left, num);
        
    else
        return busca(no->right, num);
}

int main()
{
    char s[1000];
    int freq[256];
    memset(freq, 0, sizeof(freq));
    gets(s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        freq[s[i]]++;
    }

    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *aux = head;

    for (int i = 256; i >= 0; i--)
    {
        if (freq[i] > 0)
        {
            aux->data = i;
            aux->freq = freq[i];
            aux->next = (node_t *)malloc(sizeof(node_t));
            aux = aux->next;
        }
    }
    while (head->next != NULL)
    {
        printf("%c %d\n", head->data, head->freq);
        head = head->next;
    }

    return 0;
}