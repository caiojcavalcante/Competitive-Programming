#include <stdio.h>
#include <stdlib.h>

#define cout(x) printf("%d", x)
#define endl printf("\n")
#define PRINTARRAY(array, length)    \
    for (int i = 0; i < length; i++) \
        printf("%d ", array[i]);
#define SCANARRAY(array, length)     \
    for (int i = 0; i < length; i++) \
        scanf("%d", &array[i]);

void scan(char *s)
{
    if (scanf(" %c", s) == EOF || *s == '\0')
        return;
    scan(s + 1);
}
int main()
{
    int foo, bar, baz, dia;
    char s[10000];

    scan(s);

    return 0;
}