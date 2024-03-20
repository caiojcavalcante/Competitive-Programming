#include <stdio.h>

int main()
{
    int dias, km;
    double diaria = 30.00, vt, desconto, vf;
    scanf("%d %d", &dias, &km);

    vt = (dias * diaria) + (km * 0.01);
    desconto = vt * 0.10;
    vf = vt - desconto;

    printf("%.2lf", vf);

    return 0;
}