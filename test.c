#include <stdio.h>
#define endl printf("\n")
typedef unsigned char byte;
typedef unsigned char bool;

bool is_bit_i_set(byte b, int i)
{
    return (b & (1 << i)) != 0;
}

int main()
{
    int a;
    scanf("%d", &a);
    
    for(int i = 7; i >= 0; i--)
        printf("%d", is_bit_i_set(a, i));

    endl;
    return 0;
}