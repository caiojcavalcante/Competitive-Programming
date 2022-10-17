#include <stdio.h>

int loop()
{
    float preco_original, preco_desconto;
    if(scanf("%f %f")== EOF)
        return 0;
    return (preco_desconto == preco_original * 0.8) + loop();
}
int main() {
    printf("%d", loop());
    return 0;
}