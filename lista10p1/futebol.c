#include <stdio.h>

#define endl printf("\n")

void bubble_sort(int arr[], int l, int r)
{
    if (r == 0) 
        return;
 
    if (l == r) 
        return bubble_sort(arr, 0, r - 1);
 
    if (arr[l] > arr[l + 1]) 
    {
        int aux = arr[l];
        arr[l] = arr[l + 1];
        arr[l + 1] = aux;
    }
    
    bubble_sort(arr, l + 1, r);
}

int main()
{
    int jogos, gols, score = 0, aliado, rival;
    scanf("%d %d", &jogos, &gols);
    int gols_por_jogo[jogos];
    
    for(int i = 0; i < jogos; i++)
    {
        scanf("%d%d", &aliado, &rival);

        gols_por_jogo[i] = rival - aliado;
    }

    bubble_sort(gols_por_jogo, 0, jogos - 1);

    for(int i = 0; i < jogos; i++)
    {
        if(gols <= 0)
            break;

        if(gols_por_jogo[i] < 0)
            continue;

        while(gols > 0 && gols_por_jogo[i] >= 0)
        {
            gols_por_jogo[i]--;
            gols--;
        }
    }

    for(int i = 0; i < jogos; i++)
    {
        if(gols_por_jogo[i] < 0)
            score += 3;
        else if(gols_por_jogo[i] == 0)
            score += 1;
    }

    printf("%d\n", score);

    return 0;
}