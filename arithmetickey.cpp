#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int *arr, int left, int right) {
  int pivot = arr[right];
  int i = (left - 1);

  for (int j = left; j <= right - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[right]);
  return (i + 1);
}
void quick_sort(int *arr, int left, int right) {
    if(left >= right)
        return;
    int pivot = left;

    int index = partition(arr, left, right);

    quick_sort(arr, left, index - 1);
    quick_sort(arr, index + 1, right);
}
int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}
int mmc(int a, int b)
{
    return a * (b / mdc(a, b));
}
int main()
{
    int numeros[4];
    int n;
    scanf("%d", &n);
    printf("a");
    for(int j = 0; j < n; j++)
    {
        printf("b\n");
        for(int i = 0; i < 4; i++)
        {
            scanf("%d", &numeros[i]);
        }
        quick_sort(numeros, 0, 3);
        printf("%d", mmc(numeros[2], numeros[3]) * mdc(numeros[0], numeros[1]));
    }
    return 0;
}