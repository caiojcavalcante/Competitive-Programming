#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    short a[10005], b[10005], aux, max_size;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int size, i;
    char s[10005];

    scanf("%s", s);
    size = strlen(s);
    
    i = 0;
    int j = size - 1;

    while (i < j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
    printf("%s\n", s);

    for(i = 0; i < size; i++)
        a[i] = s[i] - '0';

    max_size = size;

    scanf("%s", s);
    size = strlen(s);
    
    i = 0;
    j = size - 1;

    while (i < j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    printf("%s\n", s);
    
    for(i = 0; i < size; i++)
        b[i] = s[i] - '0';

    max_size = max(max_size, size);

    printf("%d\n", max_size);

    for (int i = 0; i < max_size; i++)
    {
        aux = a[i] + b[i];
        a[i] = aux % 10;
        a[i + 1] += (aux > 9);
    }
    for(int i = 0; i < max_size; i++)
        printf("%d", a[i]);

    return 0;
}