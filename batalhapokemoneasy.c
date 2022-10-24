#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int rodada(int vidaA, int vidaB, int ataqueA, int ataqueB)
{
    if(vidaA <= 0)
        return 1;
    if(ceil((double) vidaB / ataqueA) <= ceil((double) vidaA / ataqueB))
        return 0;
    return rodada(vidaA - ataqueB, vidaB, ataqueA + 50, ataqueB);
}
void jogo(int i)
{
    if(i == 0)
        return;
    int vidaA, vidaB, ataqueA, ataqueB;
    
    scanf("%d%d%d%d", &vidaA, &vidaB, &ataqueA, &ataqueB);
    
    printf("%s\n", rodada(vidaA, vidaB, ataqueA, ataqueB) ? "Bezaliel":"Clodes");
    jogo(i - 1);
}
int main()
{
    int rodadas;
    scanf("%d", &rodadas);
    jogo(rodadas);
	return 0;
}