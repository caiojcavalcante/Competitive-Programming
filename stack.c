#include <stdio.h>

int scan(int n)
{
    u_int16_t val, contador, next_val;
    scanf("%hd", &val);

    if(n == 0) return (int)(val);
    u_int32_t ret = scan(n - 1);

    contador = (u_int16_t)(ret >> sizeof(val));
    ret = (ret & 0b0000000011111111);
    next_val = (u_int16_t)ret;

    contador += (next_val == val);

    ret += contador << sizeof(contador);
    return ret;
}
int main()
{
    unsigned int n;
    scanf("%d", &n);
    int ret = scan(n);
    ret = (ret >> (sizeof(ret) / 2));
    printf("%d", ret);
    return 0;
}