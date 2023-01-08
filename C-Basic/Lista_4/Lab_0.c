#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


struct lista{
    int info;
    struct lista *prox;};
typedef struct lista Lista;


void inserirOrdenado(Lista **L,int num){
    
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    
    if (*L==NULL){ //lista vazia, insere no inicio
        aux->info = num;
        aux->prox = *L;
        *L = aux;
        
    }else{
        
        Lista *anterior, *atual = *L; //lista com n>0 elementos, cria elemento atual e anterior
        while(atual!=NULL && atual->info < num){ // case (0^1 else | 1^0 if | 0^0 else) 
            anterior = atual; //anterior preserva o ponteiro atual
            atual = atual->prox; //atual incrementa para chegar no proximo
        }
        
        if(atual == *L){ //se o atual for igual ao inicio, insere no incio
            aux->info = num;
            aux->prox = *L;
            *L = aux;
            
        }else{ //se não,  
            aux->info = num;
            aux->prox = anterior->prox; //aux apontará para onde o ponteiro do elemento maior que num aponta
            anterior->prox = aux; //anterior apontará para onde o elemento que foi inserido, consertando o encadeamento
        }
    }
}


void printar(Lista *L){
    Lista *aux = L;
    while(aux!=NULL){
        printf("%d",aux->info);
        printf("->");
        aux = aux->prox;
    }
    printf("NULL");
}



int main(){

    Lista *L;
    L = NULL;
    int num;
    
    printf("Digite um numero para ser inserido na lista:");
    scanf("%d",&num);
    
    while(num>0){
        inserirOrdenado(&L,num);
        printf("Digite um numero para ser inserido na lista:");
        scanf("%d",&num);
    }
    printar(L);

    return 0;
}
