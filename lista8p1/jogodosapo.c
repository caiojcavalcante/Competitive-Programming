#include <stdio.h>

int main()
{
    int n, m, o, jogador = 0, jogada, posicao_atual;
    scanf("%d%d%d", &n, &m, &o);
    int tabuleiro[n], posicoes[m];
    memset(posicoes, 0, sizeof(posicoes));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tabuleiro[i]);
    }
    for(int i = 0; i < n * o; i++)
    {
        scanf("%d", &jogada);
        posicao_atual = posicoes[jogador] + jogada;

        while(posicao_atual < 0)
            posicao_atual += n;
    
        while(posicao_atual > n)
            posicao_atual -= n;
    
        posicoes[jogador] += jogada + tabuleiro[posicoes[jogador] + jogada];   

        while(posicoes[jogador] < 0)
            posicoes[jogador] += n;
        
        while(posicoes[jogador] > n)
            posicoes[jogador] -= n;
    }
    for(int i = 0; i < m; i++)
        printf("%d\n", posicoes[i]);
    return 0;
}