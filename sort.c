#include <stdio.h>
#include <stdlib.h>

#define cout(x) printf("%d", x)
#define endl printf("\n")
#define PRINTARRAY(array, length) for(int i = 0; i < length; i++) printf("%d ", array[i]);
#define SCANARRAY(array, length) for(int i = 0; i < length; i++) scanf("%d", &array[i]);

typedef int tipo;

void merge(tipo a[], tipo b[], int size_a, int size_b)
{
    tipo* c = malloc(sizeof(tipo) * (size_a + size_b));

    int i = 0, index_a = 0, index_b = 0;
    while(index_a < size_a && index_b < size_b)
    {
        if (a[index_a] < b[index_b]) c[i++] = a[index_a++];
        else c[i++] = b[index_b++];
    }

    while(index_a < size_a){
        c[i++] = a[index_a++];
    }

    while(index_b < size_b){
        c[i++] = b[index_b++];
    }

    for(i = 0; i < size_a + size_b; i++){
        a[i] = c[i];
    }
    free(c);
}

void merge_sort(tipo* a, int left, int right)
{
    if(right <= left)
        return;
    
    int mid = (right + left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a + left, a + mid + 1, mid - left + 1, right - mid);
}

void bubble_sort(tipo arr[], int l, int r)
{
    if (r == 1) 
        return;
 
    if (l + 1 == r) 
        return bubble_sort(arr, 0, r - 1);
 
    if (arr[l] > arr[l + 1]) 
    {
        tipo aux = arr[l];
        arr[l] = arr[l + 1];
        arr[l + 1] = aux;
    }
    
    bubble_sort(arr, l + 1, r);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int biggest(tipo arr[], int r)
{
    if(r == 0) return 0;

    return max(arr[r], biggest(arr, r - 1));
}

void count_sort(int arr[], int l, int r)
{
    int max = biggest(arr, r);
    int* counter = calloc(max + 2, sizeof(int));

    for(int i = l; i <= r; i++) counter[arr[i]]++;

    int index = 0, i = l;
    while(index <= max + 1)
    {
        while(counter[index])
        {
            arr[i++] = index;
            counter[index]--;
        }
        index++;
    }
}

int main()
{
    int arr[10] = {8, 3, 10, 5, 5, 1, 9, 4, 6, 7};
 
    int start = 0, end = sizeof(arr) / sizeof(tipo) - 1;

    PRINTARRAY(arr, end + 1);endl;

    // bubble_sort(arr, start, end);
    // merge_sort(arr, start, end);
    // count_sort(arr, start, end);
 
    PRINTARRAY(arr, end + 1);endl;
 
    return 0;
}