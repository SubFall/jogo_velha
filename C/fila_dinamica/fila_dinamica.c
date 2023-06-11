#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

typedef struct NO{
    int dado;
    struct NO* prox;
}NO;

typedef struct FILA{
    NO* inicio;
    NO* fim;
}FILA;

FILA fila;

void push_push(int dado);
int pop();
void imprimir();
void menu();
void limparBuffer();

int main(){
    setlocale(LC_ALL, "Portuguese");

    int dado, op;
    fila.inicio = fila.fim = NULL;

    do
    {
        menu();
        printf("\nQual opcão? ");
        scanf("%d", &op);
        limparBuffer();

        switch (op){
        case 0:
            break;
        case 1:
            printf("Qual valor ? ");
            scanf("%d", &dado);
            limparBuffer();
            push_push(dado);
            break;
        case 2:
            dado = pop();
            if(dado == -1){
                printf("Fila, vázia");
            }else{
                printf("Valor removido %d\n", dado);
            }
            break;
        case 3:
            imprimir();
            break;
        default:
            printf("\nOpcão inválida\n");
            break;
        }
    } while (op != 0);
    
}

void push_push(int dado){
    NO* ptr = (NO*)malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = NULL;

    if(fila.inicio == NULL){
        fila.inicio = ptr;
    }else{
        fila.fim->prox = ptr;
    }
    fila.fim = ptr;
}

int pop(){
    NO* ptr = fila.inicio;
    int dado;
    if(fila.inicio == NULL){
        return -1;
    }else{
        fila.inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
    }
    free(ptr);
    return dado;
}

void imprimir(){
    NO* current = fila.inicio;
    printf("Inicio -> ");
    while(current != NULL){
        printf("%d ", current->dado);
        current = current->prox;
    }
    printf("<- Fim");
    printf("Pressione a tecla 'ENTER'");
    getchar();
    
}

void menu(){
    printf("\n1-Inserir\n2-Remover\n3-Imprimir\n0-Sair\n");
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n') {
        // Descarta o caractere
    }
}