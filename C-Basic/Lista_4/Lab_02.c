#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
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
        while(atual!=NULL && atual->info < num){ // case (0^0 if | 0^1 if | 1^0 else | 1^1 else) 
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


void printar(Lista *L,int *v,int tam){
    Lista *aux = L;
    printf("\nLista\n");
    while(aux!=NULL){
        printf("%d",aux->info);
        printf("->");
        aux = aux->prox;
    }
    printf("NULL\n");
    printf("Vetor\n");
    
    for(int i=0;i<tam;i++){
        printf("%d\n",v[i]);
    }
}

void destroi(Lista *L){
    Lista *anterior = NULL;
    Lista *atual = L;
    while (atual != NULL){
        anterior = atual->prox;
        free(atual);
        atual = anterior;
    }
}

int main(){
    int *v;
    int tam;
    Lista *L;
    L = NULL;

    printf("Digite o tamanho do array: ");
    scanf("%d",&tam);

    v = (int *)malloc(tam*sizeof(int));
    for(int i=0;i<tam;i++){
        printf("Digite um elemento: ");
        scanf("%d",&v[i]);
    }
    
    for(int i=0;i<tam;i++){
        inserirOrdenado(&L,v[i]);
    }
        
    printar(L,v,tam);
    free(v);
    destroi(L);

return 0;
}
