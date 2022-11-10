#include <stdio.h>
#include <string.h>	

int main()
{
    int tamanho_tabuleiro, quantidade_sapos, numero_rodadas, dado, sapo;
    scanf("%d %d %d", &tamanho_tabuleiro, &quantidade_sapos, &numero_rodadas);
    int posicao_sapos[quantidade_sapos], tabuleiro[tamanho_tabuleiro];
    
    memset(posicao_sapos, 0, sizeof(posicao_sapos));

    for (int i = 0; i < tamanho_tabuleiro; i++)
        scanf("%d", &tabuleiro[i]);

    for(int i = 0; i < quantidade_sapos * numero_rodadas ; i++)
    {
        scanf("%d", &dado);
        
        sapo = i % quantidade_sapos;

        posicao_sapos[sapo] += dado;

        posicao_sapos[sapo] = posicao_sapos[sapo] % tamanho_tabuleiro;

        if(posicao_sapos[sapo] < 0)
            posicao_sapos[sapo] += tamanho_tabuleiro;

        posicao_sapos[sapo] += tabuleiro[posicao_sapos[sapo]];
    }

    for(int i = 0; i < quantidade_sapos; i++)
        printf("%d\n", posicao_sapos[i]);

    return 0;
}