#include <stdio.h>

int pontos(int questao, char gabarito[11])
{
    if (questao < 0) return 0;
    char resposta;
    scanf("%c", &resposta);
    if(resposta == ' ')
        questao++;
    return (gabarito[10 - questao] == resposta) + pontos(questao - 1, gabarito);
}
void correcao(char gabarito[11], int index, int* alunos_totais, int* alunos_aprovados, int notas[10])
{
    int aluno;
    if (scanf("%d", &aluno) && aluno == 9999) return;
    int pontuacao = pontos(10, gabarito);
    *alunos_totais += 1;
    *alunos_aprovados += (pontuacao >= 6);
    notas[pontuacao]++;
    printf("%d %d.0\n", index, pontuacao);
    correcao(gabarito, index + 1, alunos_totais, alunos_aprovados, notas);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int maior(int notas[10], int index, int maxindex)
{
    if (index < 0) return maxindex;

    if (notas[index] > notas[maxindex])
        maxindex = index;
        
    return maior(notas, index - 1, maxindex);
}
int main()
{
    int alunos_totais = 0, alunos_aprovados = 0;
    int notas[11] = {0};
    char gabarito[11];
    scanf("%s", gabarito);
    correcao(gabarito, 1, &alunos_totais, &alunos_aprovados, notas);
    printf("%.1lf%%\n%d.0", alunos_aprovados * 100 / (double)alunos_totais, maior(notas, 10, 10));
    return 0;
}