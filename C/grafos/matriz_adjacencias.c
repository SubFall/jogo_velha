#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define maximo 10

int ma[maximo][maximo];
int tamanho = 0;

int grafro_tamanho();
void inserir_aresta(int num1, int num2);
void remover_aresta(int num1, int num2);
void exibir_ma();
void menu();

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num1, num2, op;

    do
    {
    menu();
    printf("Qual opcão: ");
    scanf("%d", &op);
    fflush(stdin);
    switch(op){
    case 0:
        break;
    case 1:
        tamanho = grafro_tamanho();
        break;
    case 2:
        printf("Inserir o valor de cada vértice: ");
        scanf("%d%d", &num1, &num2);
        fflush(stdin);
        inserir_aresta(num1, num2);
        break;
    case 3:
        printf("Qual vértice deseja remover: ");
        scanf("%d%d", &num1, &num2);
        fflush(stdin);
        remover_aresta(num1, num2);
        break;
    case 4:
        exibir_ma();
        break;
    default:
        printf("Opcão inválida\n Pressione 'ENTER'");
        break;
    }
    } while (op != 0);
}

int grafro_tamanho(){
    int tam = 0;
    while(tam > maximo || tam < 1){
        printf("Escolha a quantidade de vértices: ");
        scanf("%d", &tam);
        fflush(stdin);
    }
    return tam;
}

void inserir_aresta(int num1, int num2){
    if(num1 > tamanho-1 || num2 > tamanho -1 || num1 < 0 || num2 < 0){
        printf("Erro!\n");
        printf("Pressione 'ENTER'\n");
        getchar();
    }else{
        ma[num1][num2] = 1;
        ma[num2][num1] = 1;
    }
}

void remover_aresta(int num1, int num2){
    if(num1 > tamanho-1 || num2 > tamanho-1 || num1 < 0 || num2 < 0){
        printf("Eroo!\n");
        printf("Pressione 'ENTER'");
        getchar();
    }else{
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
    }
    
}

void exibir_ma(){
    printf("Matriz de arestas: \n");
    int i;
    int j;
    for (i = 0; i < tamanho; i++){
        printf("[ ");
        for (j = 0; j < tamanho; j++){
            printf("%d ", ma[i][j]);
        }
        printf("]\n");
        
    }
    printf("Pressione 'ENTER'\n");
    getchar();
    
}

void menu(){
    printf("1 - Ajustar tamanho do grafo\n2 - Inserir aresta\n3 - Remover aresta\n4 - Imprimir o grafo\n0 - Sair\n");
}