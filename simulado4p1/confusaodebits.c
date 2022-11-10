#include <stdio.h>

#define cout(x) printf("%d", x)
#define endl printf("\n")
#define PRINTARRAY(array, length) for(int i = 0; i < length; i++) printf("%d ", array[i]);

int max(int a, int b)
{
    return a > b ? a : b;
}
int count(int a[], int index, int size, int last)
{
    if(index == size || a[index] == last)
        return 0;
    return 1 + count(a, index + 1, size, a[index]);
}
int get_max(int a[], int index, int size)
{
    if(index > size)
        return 0;
    return max(count(a, index, size, 2), get_max(a, index + 1, size));
}
void scan(int i, int a[])
{
    if(i)
        scan(i - 1, a);
    scanf("%d", &a[i]);
}
void solve(int i)
{
    if(i == 0)
        return;
    int size;
    scanf("%d", &size);
    int bits[size];
    scan(size, bits);
    cout(get_max(bits, 0, size));
    solve(i - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    solve(n);
}