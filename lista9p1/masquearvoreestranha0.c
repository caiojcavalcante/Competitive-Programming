#include <stdio.h>
#define RIGHT 0
#define LEFT 1

int max(int a, int b)
{
    return a > b ? a : b;
}
int get_tree_size(int root, int aux, int m[][2], int root_found)
{
    if(aux == root) root_found++;
    if(aux == -1) return 0;
    return root_found + max(get_tree_size(root, m[aux][LEFT], m, root_found), get_tree_size(root, m[aux][RIGHT], m, root_found));
}
int main()
{
    int n, k, r, aux;
    scanf("%d%d%d", &n, &k, &r);

    int m[n][2];

    memset(m, -1, sizeof(m));

    for(int i = 0; i < k; i++)
    {
        scanf("%d", &aux);
        scanf("%d%d", &m[aux][0], &m[aux][1]);
    }
    printf("%d", get_tree_size(r, r, m, 0));
    return 0;
}