#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *x, void *y, size_t size)
{
    void* aux = malloc(size);
    memcpy(aux, x, size);
    memcpy(x, y, size);
    memcpy(y, aux, size);
    free(aux);
}
 
int bigger_f(void* a, void* b)
{   
    return *(double*)a > *(double*)b;
}
int bigger_d(void* a, void* b)
{   
    return *(int*)a > *(int*)b;
}
 
void sort(int a[], int i, int size, int (*cmp)(void *, void *))
{
    if(size == 0)
        return;
 
    if(i == size)
        return sort(a, 0, size - 1, cmp);

    if(cmp(&a[i], &a[i + 1])) {
        swap(&a[i], &a[ i + 1], sizeof(*a));
    }
 
    sort(a, i + 1, size, cmp);
}

void print_arr(int a[], int size)
{
    if(size > 0)
        print_arr(a, size - 1);
    
    printf("%d ", a[size]);
}
int main()
{
    int arr[4];

    for(int i = 0; i < 4; i++)
        scanf("%d", &arr[i]);
    print_arr(arr, 3);
    printf("\n");
 
    sort(arr, 0, 3, bigger_d);
    print_arr(arr, 3);
    printf("\n");
 
    // sort(arr, 0, 1, 4, smaller);
    // print_arr(arr, 3);
    // printf("\n");
 
    // printf("%.2d\n%.2d\n%.2d\n%.2d\n", arr[0], arr[2], arr[3], arr[1]);
    
    return 0;
}