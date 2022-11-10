#include <stdio.h>
#include <string.h>

#define cout(x) printf("%d", x)
#define endl printf("\n")
#define PRINTARRAY(array, length) for(int i = 0; i < length; i++) printf("%.2lf ", array[i]);
#define SCANARRAY(array, length) for(int i = 0; i < length; i++) scanf("%d", &array[i]);

typedef double tipo;

void bubble_sort(tipo arr[], int l, int r)
{
    if (r == 1) 
        return;
 
    if (l + 1 == r) 
        return bubble_sort(arr, 0, r - 1);
 
    if (arr[l] < arr[l + 1]) 
    {
        tipo aux = arr[l];
        arr[l] = arr[l + 1];
        arr[l + 1] = aux;
    }
    
    return bubble_sort(arr, l + 1, r);
}
int scan(int n, double ec[], double cc[])
{
    if(n == 0) return 0;
    double leitura;
    char curso;
    scanf("%lf %c", &leitura, &curso);
    if(curso == 'e')
    {
        ec[n - 1] = leitura;

    }
    else
    {
        cc[n - 1] = leitura;
    }
    return (curso == 'e') + scan(n - 1, ec, cc);
}
void print(double arr[], int n)
{
    if(n == 0) return;
    printf("%.2lf ", arr[n - 1]);
    return print(arr, n - 1);
}
int main()
{
    double ec[10], cc[10];
    int ret = scan(10, ec, cc);

    bubble_sort(ec, 0, 10);
    bubble_sort(cc, 0, 10);

    printf("EC: ");
    print(ec, ret);
    printf("\nCC: ");
    print(cc, 10 - ret);
    printf("\n");

    return 0;
}