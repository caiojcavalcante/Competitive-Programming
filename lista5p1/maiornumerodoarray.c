#include <stdio.h>

arr[1000];
int getGreater(int max, int index)
{
    if (index == 0)
        return max;
    if (arr[index] > max)
        max = arr[index];
    getGreater(max, index - 1);
}
void scan(int i)
{
    scanf("%d", &arr[i]);
    if (arr[i] == 0)
        return i;
    scan(i + 1);
}
int main()
{
    int ret = scan(0);
    
    printf("%d", getGreater(ret));
    return 0;
}