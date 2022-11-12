#include <stdio.h>

int main()
{
    int operacao;
    double valor, saldo = 0, creditados = 0;
    while(1)
    {
        scanf("%d%lf", &operacao, &valor);

        if(operacao == -1)
            break;

        saldo += (operacao == 1 ? valor : -valor);

        creditados += (operacao == 1 ? valor : 0);
    }
    printf("Creditos: R$ %.2lf\n", creditados);
    printf("Debitos: R$ %.2lf\n", -saldo + creditados);
    printf("Saldo: R$ %.2lf\n", saldo);

    return 0;
}