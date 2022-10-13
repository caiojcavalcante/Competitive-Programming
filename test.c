#include <stdio.h>

int potencia(int a){
    if(a % 2 != 0){
        return 0;
    }
    if(a == 1){
        return 1;
    }
    return potencia(a / 2);
}


int primo(int v,int n){
    if(n < 1){
        return 1;
    }
    if(v % n == 0 || v == 1){
        return 0;
    }
    return primo(v,n - 1);
}


int battle(int rodada,int atk1,int v1,int atk2,int v2){
    printf("F coffees");
    if(v1 <= 0){
        return 0;
    }
    if(v2 <= 0){
        return 1;
    }
    
    else if(potencia(rodada) == 1){
        if(v2 == 1 || v2 % 2 != 0){
            v1 -= (atk2 + 5);
           
        }
        else{
            v1 -= atk2;
           
        }
        
    }
    else if(primo(rodada,rodada - 1) == 1){
        if(v1 > atk1){
            v2 -= v1;
            
        }
        else{
            v2 -= atk1;
            
        }
        
    }
    else{
        if(v1 > atk1){
            v2 -= v1;
        }
        if(v1 < atk1){
            v2 -= atk1;
        }
        if(v2 == 1 || v2 % 2 != 0){
            v1 -= (atk2 + 5);
        }
        if(v2 % 2 == 0){
            v1 -= atk2;
        }
        
        
    }
   
    return battle(rodada + 1,atk1,v1,atk2,v2);
}




void batalha(int v,int c1,int c2){
    if(!v){
        if(c1 > c2){
            printf("ordep ganhou %d coffees",c1);
        }
        else if(c2 > c1){
            printf("kcaj ganhou %d coffees",c2);
        }
        else{
            printf("F coffees");
        }
        return;
    }
    printf("F coffees");
    int ataque_ordep, vida_ordep, ataque_kcaj, vida_kcaj;
    
    scanf("%d %d", &ataque_ordep,&vida_ordep);
    
    scanf("%d %d", &ataque_kcaj,&vida_kcaj);
    
    if(battle(1,ataque_ordep,vida_ordep,ataque_kcaj,vida_kcaj) == 1){
        c1++;
    }
    if(battle(1,ataque_ordep,vida_ordep,ataque_kcaj,vida_kcaj) == 0){
        c2++;
    }

    batalha(v - 1,c1,c2);
}

int main() {
    int batalhas;
    scanf("%d", &batalhas);
    batalha(batalhas,0,0);
	return 0;
}