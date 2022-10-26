#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONA
void swap(void *x, void *y, size_t size)
{
    void* aux = malloc(size);
    memcpy(aux, x, size);
    memcpy(x, y, size);
    memcpy(y, aux, size);
    free(aux);
}
// NAO FUNCIONA
// int bigger(void* a, void* b, size_t size)
// {
//     return memcmp(a, b, size) > 0;
// }
int bigger(void* a, void* b)
{
    int ret = *(double*)a > *(double*)b;
    printf("%.1lf = %.1lf %d\n", *(double*)a, *(double*)b, ret);
    return ret;
}
int smaller(void* a, void* b)
{
    return 0;
}
void sort(void *a, size_t type, int i, int size, int (*cmp)(void *, void *))
{
    if(size == 0)
        return;

    if(i + 1 >= size)
        return sort(a, 0, type, size - 1, cmp);

    if(cmp(a + type * i, a + type * (i + 1)))
        swap(&a[i], &a[i + 1], sizeof(*a));

    sort(a, i + 1, type, size, cmp);
}
void print_arr(double a[], int size)
{
    if(size > 0)
        print_arr(a, size - 1);
    
    printf("%.2lf ", a[size]);
}
void scanreader(double *a, int counter)
{
    if (counter > 3)
        return;
    scanf("%lf", a + counter);
    scanreader(a, counter + 1);
}
int main()
{
    double arr[4];
    scanreader(arr, 0);

    print_arr(arr, 3);
    printf("\n");

    sort(arr, sizeof(double), 0, 4, bigger);
    print_arr(arr, 3);
    printf("\n");

    // sort(arr, 0, 1, 4, smaller);
    // print_arr(arr, 3);
    // printf("\n");

    // printf("%.2lf\n%.2lf\n%.2lf\n%.2lf\n", arr[0], arr[2], arr[3], arr[1]);
    
    return 0;
}