#include <stdio.h>
#include <stdlib.h>


struct lista{
    int num;
    struct lista *prox;};
typedef struct lista Lista;

int pertence(Lista *L,int elem){
    if(L==NULL) return 0;
    else if(L->num == elem)return 1;
    else return pertence(L->prox,elem);
}


void inserir(Lista **L){
    
    Lista *aux;
    aux = (Lista*)malloc(sizeof(Lista));
    
    *L==NULL;
    printf("Digite um numero: ");
    scanf("%d",&aux->num);
    aux->prox = *L;
    *L = aux;
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

    Lista *L;
    L = NULL;
    int num, elem;
    
    printf("Digite o tamanho da lista: ");
    scanf("%d",&num);
    
    while(num>0){
        inserir(&L);
        num--;
    }
    
   printf("Digite o inteiro que deseja procurar: ");
   scanf("%d",&elem);

   if(pertence(L,elem))printf("Pertence");
   else printf("Nao pertence");
   
    if(L==NULL){
        free(L);
    }else destroi(L);

    return 0;
}
