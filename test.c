#include <stdio.h>
#include <stdlib.h>
#define cout(x) printf("%d", x)
#define endl printf("\n")

typedef int tipo;

void merge(tipo a[], tipo b[], int size_a, int size_b)
{
    tipo* c = malloc(sizeof(tipo) * (size_a + size_b));

    int i = 0, index_a = 0, index_b = 0;
    while(index_a < size_a && index_b < size_b)
    {
        if(a[index_a] < b[index_b])
            c[i++] = a[index_a++];
        else
            c[i++] = b[index_b++];
    }
    while(index_a < size_a)
        c[i++] = a[index_a++];

    while(index_b < size_b)
        c[i++] = b[index_b++];

    for(int i = 0; i < size_a + size_b; i++)
        a[i] = c[i];

    free(c);
}

void merge_sort(tipo* a, int left, int right)
{
    if(right - left <= 1)
        return;
    
    int mid = right / 2;

    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, a + mid, mid, right - mid);
}

void bubble_sort(int l, int r, tipo arr[])
{
    if (r == 1) 
        return;

    if (l + 1 == r) 
        return bubble_sort(0, r - 1, arr);

    if (arr[l] > arr[l + 1]) 
    {
        tipo aux = arr[l];
        arr[l] = arr[l + 1];
        arr[l + 1] = aux;
    }
    
    return bubble_sort(l + 1, r, arr);
}
int main()
{
    int a[3] = {1, 3, 5}, b[3] = {2, 4, 6};

    int* arr = malloc(sizeof(int) * 6);

    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 4;
    arr[5] = 6;

    // merge(a, b, 3, 3);
    merge_sort(arr, 0, 6);

    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    endl;
    return 0;
}