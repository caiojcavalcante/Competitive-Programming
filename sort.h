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
int bigger(double a, double b)
{
    return a > b;
}
int smaller(double a, double b)
{
    return a < b;
}
void sort(double a[], int i, int j, int size, int (*cmp)(double, double))
{
    if(size == 0)
        return;

    if(j >= size)
    {
        return sort(a, 0, 1, size - 1, cmp);
    }
    if(cmp(a[i], a[j]))
        swap(&a[i], &a[j], sizeof(*a));

    sort(a, i + 1, j + 1, size, cmp);
}