#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 3

void iniciar_matriz();
void iniciar_jogo();
void imprimir_matriz();
int verificar_se_ganhou(char jogo[MAX_SIZE][MAX_SIZE], char jogador);

char jogo[MAX_SIZE][MAX_SIZE];
int i, j, linha, coluna, op = 1;
char jogador = 'X', finaliza = '1';
int main(){
    do{
        iniciar_matriz();
        while(finaliza != 2){
            iniciar_jogo();
        }
        imprimir_matriz();
        printf("\nDeseja Continuar ? 1 - SIM / 0 - NAO\n");
        scanf("%d", &op);
        finaliza = '1';
    }while(op != 0);
}

void iniciar_matriz(){
    for(i = 0; i < MAX_SIZE; i++){
        for(j = 0; j < MAX_SIZE; j++){
            jogo[i][j] = ' ';
        }
    }   
}

void iniciar_jogo(){ 

    imprimir_matriz();

    //validar jogada
    do{
        printf("Jogador %c, qual linha e coluna: ", jogador);
        scanf("%d%d", &linha, &coluna);
    }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

    if(jogador == 'X'){
        jogo[linha][coluna] = jogador;
        finaliza = verificar_se_ganhou(jogo, jogador);
        jogador = '0';
    }else{
        jogo[linha][coluna] = jogador;
        finaliza = verificar_se_ganhou(jogo, jogador);
        jogador = 'X';
    }

    if(finaliza != 1)
        printf("\nFim do jogo\n");
}

void imprimir_matriz(){
       for(i = 0; i < MAX_SIZE; i++){
        for(j = 0; j < MAX_SIZE; j++){
            printf(" %c ", jogo[i][j]);
            if(j < 2)
                printf("|");
        }
        if(i < 2)
            printf("\n-----------");
        printf("\n");
    }  
}

int verificar_se_ganhou(char jogo[MAX_SIZE][MAX_SIZE], char jogador){
    //verifica as linhas
    for (linha = 0; linha < MAX_SIZE; linha++){
        if(jogo[linha][0] == jogador && jogo[linha][1] == jogador && jogo[linha][2] == jogador)
            return 2;
    }

    //verifica coluna
    for (coluna = 0; coluna < MAX_SIZE; coluna++){
        if(jogo[0][coluna] == jogador && jogo[1][coluna] == jogador && jogo[2][coluna] == jogador)
            return 2;
    }
    
    //verifica diag. principal
    if(jogo[0][0] == jogador && jogo[1][1] == jogador && jogo[2][2] == jogador)
        return 2;
    
    //verifica diag. secundaria
    if(jogo[0][2] == jogador && jogo[1][1] == jogador && jogo[2][0] == jogador)
        return 2;

    return 1;
    }
