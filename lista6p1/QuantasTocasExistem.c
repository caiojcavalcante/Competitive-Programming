#include <stdio.h>

int grafo[10005];
int visited[10005];
int first_not_visited(int index, int size)
{
    if(index >= size)
        return -1;
    if (!visited[index])
        return index;
    return first_not_visited(index + 1, size);
}
void scan_graph(int size)
{
    if(size)
        scan_graph(size - 1);
    scanf("%d", &grafo[size]);
}
int count_loops(int iteration, int size)
{
    if(iteration == -1)
        return 0;
    if(visited[iteration])
        return 1 + count_loops(first_not_visited(0, size), size);
    visited[iteration] = 1;
    return count_loops(grafo[iteration], size);
}
int main()
{
    int size;
    scanf("%d", &size);
    scan_graph(size - 1);
    printf("%d", count_loops(0, size));
    for(int i = 0; i < size; i++)
    {
        printf("%d ", grafo[i]);
    }
}