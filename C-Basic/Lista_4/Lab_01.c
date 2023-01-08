#include <stdio.h>
#include <stdlib.h>


struct lista{
    int info;
    struct lista *prox;};
typedef struct lista Lista;

Lista *inserirInicio(Lista *L,int num){
    
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    aux->info = num;
    aux->prox = L;
    return aux;reo
}

void printar(Lista *L){
    while(L!=NULL){
        printf("->");
        printf("%d",L->info);
        L = L->prox;
    }
}


int main(){

    Lista *L;
    int num;
    L = NULL;
    printf("Digite um numero para ser inserido na lista:");
    scanf("%d",&num);
    
    while(num>0){
        L = inserirInicio(L,num);
        printf("Digite um numero para ser inserido na lista:");
        scanf("%d",&num);
    }
    printar(L);
    return 0;

}

/* PONTEIRO DUPLO E VOID

#include <stdio.h>
#include <stdlib.h>


struct lista{
    int info;
    struct lista *prox;};
typedef struct lista Lista;


void inserirInicio(Lista **L,int num){
    
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    aux->info = num;
    aux->prox = *L; //FAZ O PONTEIRO AUXILIAR APONTAR PARA O PRIMEIRO
    *L = aux; //FAZ O PONTEIRO PRINCIPAL APONTAR PARA O PONTEIRO AUXILIAR
    
}

int buscar(Lista *L,int num){
    Lista *aux = L;
    while(aux!=NULL){
        if(aux->info == num){return 1;}
        else{return 0;}
}

void printar(Lista *L){
    Lista *aux = L;
    while(aux!=NULL){
        printf("->");
        printf("%d",aux->info);
        aux = aux->prox;
    }
}

int main(){

    Lista *L;
    int num;
    L = NULL;
    printf("Digite um numero para ser inserido na lista:");
    scanf("%d",&num);
    
    while(num>0){
        inserirInicio(&L,num);
        printf("Digite um numero para ser inserido na lista:");
        scanf("%d",&num);
    }
    printar(L);
    return 0;
}*/
