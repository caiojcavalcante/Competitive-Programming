#include <stdio.h>

int compare(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int tamanho_pizza, azeitonas;
    scanf("%d%d", &tamanho_pizza, &azeitonas);

    int matriz[azeitonas];

    for(int i = 0; i < azeitonas; i++)
    {
        scanf("%d", &matriz[i]);
    }
    int iterador = 0;
    int* item;
    int key;
    while(1)
    {
       
    }

        iterador++;
    }
    printf("N");

    return 0;
}