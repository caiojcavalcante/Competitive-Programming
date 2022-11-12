#include <stdio.h>

#define endl printf("\n")
#define bit(x, i) (x & (1 << i))  //select the bit of position i of x
#define set(x, i) (x | (1 << i))  //set the bit of position i of x
#define low_bit(x) ((x) & ((x) ^ ((x)-1))) //get the lowest bit of x 
#define high_bit(msb, n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest 
#define abs(x) (x < 0 ? (-x) : x)
#define max(a, b) (a < b ? b : a) 
#define min(a, b) (a > b ? b : a) 
#define fill(a,x) memset(a ,x ,sizeof(a))
#define ll long long
#define ull unsigned long long
#define INF (int)1e9
#define EPS 1e-9
#define PRINTARRAY(array, length) for(int i = 0; i < length; i++) printf("%d ", array[i]);
#define SCANARRAY(array, length) for(int i = 0; i < length; i++) scanf("%d", &array[i]);


signed main()
{

    return 0;
}