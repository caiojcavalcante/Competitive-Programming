#include <stdio.h>

int grafo[10005];
int visited[10005];
int firstNonVisited(int index, int size)
{
    if(index >= size)
        return -1;
    if (!visited[index])
        return index;
    return firstNonVisited(index + 1, size);
}
void scanGraph(int size)
{
    if(size)
        scanGraph(size - 1);
    scanf("%d", &grafo[size]);
}
int countLoops(int iteration, int size)
{
    if(iteration == -1)
        return 0;
    if(visited[iteration])
        return 1 + countLoops(firstNonVisited(0, size), size);
    visited[iteration] = 1;
    return countLoops(grafo[iteration], size);
}
int main()
{
    int size;
    scanf("%d", &size);
    scanGraph(size - 1);
    printf("%d", countLoops(0, size));
    for(int i = 0; i < size; i++)
    {
        printf("%d ", grafo[i]);
    }
}