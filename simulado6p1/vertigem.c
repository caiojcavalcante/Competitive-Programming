#include <stdio.h>

#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3
#define VERTIGEM 4
#define cima     total_score, y-1,x, mapa_atual, mapas
#define baixo    total_score, y+1,x, mapa_atual, mapas
#define esquerda total_score, y,x-1, mapa_atual, mapas
#define direita  total_score, y,x+1, mapa_atual, mapas
#define circular(a, b) ((a % b + b) % b)
#define pos m[y][x]
#define mapa mapas[mapa_atual]

typedef struct casa
{
    int dir;
    int score;
} casa_t;

typedef struct vertigo
{
    int map_score;
    int h;
    int w;
    char nome[101];
    casa_t m[100][100];
} vertigo_t;

int palindromo(char * s)
{
    int i = 0, j = 0;
    while(s[i] != '\0')
        i++;i--;

    while(i > j)
        if(s[i--] != s[j++])return 0;
    return 1;
}

int move(int total_score, int y, int x, int mapa_atual, vertigo_t mapas[])
{
    x = circular(x, mapa.w);
    y = circular(y, mapa.h);
    
    mapa.map_score += mapa.pos.score * (mapa.pos.dir != VERTIGEM);

    if(x == mapa.w - 1 && y == mapa.h - 1)
    {
        if(palindromo(mapa.nome))
            mapa.map_score *= 2;
        return;
    }
    if(mapa.pos.dir == VERTIGEM)
    {
        int prox_mapa = mapa.pos.score;

        if(palindromo(mapa.nome))
            mapa.map_score *= 2;

        total_score += mapa.map_score;

        int next_map_pos = total_score % (mapas[prox_mapa].h * mapas[prox_mapa].w);
        x = next_map_pos / mapas[prox_mapa].w;
        y = next_map_pos % mapas[prox_mapa].w;
        return mapa.map_score + move(total_score, x, y, prox_mapa, mapas);
    }

    if(mapa.pos.dir == CIMA)    move(cima);
        
    if(mapa.pos.dir == BAIXO)   move(baixo);
        
    if(mapa.pos.dir == ESQUERDA)move(esquerda);
        
    if(mapa.pos.dir == DIREITA) move(direita);
}
int main()
{
    int qntd_mapas, total_pontos = 0;
    scanf("%d", &qntd_mapas);
    vertigo_t mapas[qntd_mapas];
    for(int i = 0; i < qntd_mapas; i++)
    {
        scanf("%d %d", &mapas[i].h, &mapas[i].w);
        scanf("%s", mapas[i].nome);

        for(int j = 0; j < mapas[i].h; j++)
            for(int k = 0; k < mapas[i].w; k++)
                scanf("%d,%d", &mapas[i].m[j][k].dir, &mapas[i].m[j][k].score);

        mapas[i].map_score = 0;
    }
    move(0, 0, 0, 0, mapas);
    
    for(int i = 0; i < qntd_mapas; i++)
        total_pontos += mapas[i].map_score;
    printf("%d\n", total_pontos);
    
    for(int i = 0; i < qntd_mapas; i++)
        printf("%s %d\n", mapas[i].nome, mapas[i].map_score);
}