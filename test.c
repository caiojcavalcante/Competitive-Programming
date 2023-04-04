#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *v, int size) {
    if (size <= 1) {
        return;
    }
    int pivot = v[size / 2];
    int a = 0;
    int b = size - 1;

    while (a <= b) {
        while (v[a] < pivot) {
            a++;
        }
        while (v[b] > pivot) {
            b--;
        }
        if (a <= b) { // Alteração aqui
            swap(&v[a], &v[b]);
            /*
                Avanço os ponteiros
                v + a e v + b manualmente
            */
            a++;
            b--;
        }
    }
    quick_sort(v, b + 1);
    quick_sort(v + a, size - a);
}

int main(void)
{
    int a[10] = {4, 5, 4, 2, 7, 9, 2, 6, 7, 4};
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    quick_sort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}