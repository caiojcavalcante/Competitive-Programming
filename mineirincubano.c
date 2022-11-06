#include <stdio.h>

int bigger(double a, double b)
{
    return a > b;
}
void swap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
void sort(int a[], int i, int size)
{
    if(size == 0)
        return;

    if(i == size)
        return sort(a, 0, size - 1);

    if(bigger(a[i], a[i + 1])) {
        int aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
    }

    sort(a, i + 1, size);
}
int find_index(int a[], int size, int value)
{
    if(size == 0)
        return -1;

    if(a[size] == value)
        return size;

    return find_index(a, size - 1, value);
}

int main()
{
    int arr[4], arrcpy[4], ans = 0;

    for(int i = 0; i < 4; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < 4; i++)
        arrcpy[i] = arr[i];

    sort(arr, 0, 3);
    
    for(int i = 0; i < 4; i++)
    {
        printf("%d", arr[i]);
        if(i != 3)
            printf(" ");
    }

    for(int i = 0; i < 4; i++)
    {
        if(arr[i] != arrcpy[i])
        {
            ans++;
            swap(&arrcpy[i], &arrcpy[find_index(arrcpy, 3, arr[i])]);
        }
    }
    printf("\n%d", ans);
}