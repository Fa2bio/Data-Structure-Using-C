#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

void inserirfim(Lista **L,int num){
    
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    
    if (*L==NULL){ //lista vazia, insere no inicio
        aux->info = num;
        *L = aux;
        aux->prox = aux;
        
    }else{
        
        Lista *anterior, *atual = *L; //lista com n>0 elementos, cria elemento atual e anterior
        while(atual->prox!=*L){ // case (0^1 else | 1^0 if | 0^0 else) 
            atual = atual->prox;
            //anterior = atual; //anterior preserva o ponteiro atual
            //atual = atual->prox; //atual incrementa para chegar no proximo
        }
        atual->info = num;
        aux->prox = *L;
        *L = aux;
        
        /*aux->info = num;
        aux->prox = anterior->prox; //aux apontará para onde o ponteiro do elemento maior que num aponta
        anterior->prox = aux; //anterior apontará para onde o elemento que foi inserido, consertando o encadeamento
    */}
}

void percorreLista(Lista **L1,Lista *L2){
    
    Lista *aux = L2;
    while(aux->prox!=L2){
        inserirfim(L1,aux->info);
        aux = aux->prox;
    }
}

void printar(Lista *L){
    Lista *p = L;
    while(p->prox!=L){
        printf("%d ->",L->info);
        p = p->prox;
    }
    printf("\n");
}

/*void destroi(Lista *L){
    Lista *anterior = NULL;
    Lista *atual = L;
    while (atual != NULL){
        anterior = atual->prox;
        free(atual);
        atual = anterior;
    }
}*/

int main(){

    Lista *L1,*L2;
    L1 = NULL; L2 = NULL;
    
    int taml1, taml2,elemento;
    printf("Digite o tamanho da lista 1: ");
    scanf("%d",&taml1);
        
    while(taml1>0){
        printf("Digite o elemento: ");
        scanf("%d",&elemento);
        inserirfim(&L1,elemento);
        taml1--;
    }
    
    printf("Digite o tamanho da lista 2: ");
    scanf("%d",&taml2);
    
    while(taml2>0){
        printf("Digite o elemento: ");
        scanf("%d",&elemento);
        inserirfim(&L2,elemento);
        taml2--;
    }
    
    percorreLista(&L1,L2);

    printar(L1);
   /* destroi(L1);
    destroi(L2);*/


    return 0;
}
