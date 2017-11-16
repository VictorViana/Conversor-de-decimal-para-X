#include<stdio.h>
#include<stdlib.h>
#define False 0
#define True 1
typedef struct divisao{
    int num;
    struct divisao *prox;
}Tdivisao;
void converte(int x, int b);
void create(Tdivisao**pilha);
int top(Tdivisao*pilha);
int empty(Tdivisao *pilha);
int full(Tdivisao*pilha);
void push(Tdivisao**pilha, int n);
int pop(Tdivisao**pilha);
void destroy(Tdivisao**pilha);
int main () {
    int x, b;
    printf("Digite um numero decimal inteiro\n");
    scanf("%d",&x);fflush(stdin);
    printf("Digite uma base entre 2-16, os mesmos estao inclusos\n");
    scanf("%d",&b);fflush(stdin);
    while(b>16||b<2){
        printf("BASE INVALIDA\nDigite uma base entre 2-16, os mesmos estao inclusos\n");
        scanf("%d",&b);fflush(stdin);
    }
    converte(x,b);
    system("pause");
    return 0;
}
void converte(int x, int b){
    Tdivisao*pilha;
    int aux=x, aux2;
    create(&pilha);
    if(x<b||x==b)
        printf("O numero %d na base %d eh %d\n",x,b,x);
    else{
        while(aux>=b){
            do{
                push(&pilha,(aux%b));
                aux=aux/b;
            }while(aux>b);
        }
        push(&pilha,(aux%b));
        while(empty(pilha)==False){
            aux2=pop(&pilha);
            printf("%d ",aux2);
        }
        free(pilha);
    }
}
void create(Tdivisao**pilha){
    *pilha=NULL;
}
int top(Tdivisao*pilha){
    return pilha->num;
}
int empty(Tdivisao *pilha){
    if(pilha==NULL)
        return True;
    return False;
}
int full(Tdivisao*pilha){
    return False;
}
void push(Tdivisao**pilha, int n){
    Tdivisao*novo;
    novo=(Tdivisao*)malloc(sizeof(Tdivisao));
    novo->num=n;
    novo->prox=*pilha;
    *pilha=novo;
}
int pop(Tdivisao**pilha){
    Tdivisao*aux;
    int num;
    aux=*pilha;
    *pilha=(*pilha)->prox;
    num=aux->num;
    free(aux);
    return num;
}
void destroy(Tdivisao**pilha){
    Tdivisao *aux;
    if(*pilha!=NULL){
        while(*pilha!=NULL){
            aux=*pilha;
            *pilha=(*pilha)->prox;
            free(aux);
        }
    }
    return;
}
