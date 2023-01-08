#include <stdio.h>
#include <stdlib.h>

struct lista{
    int num;
    struct lista *prox;};
typedef struct lista Lista;

Lista *criaLista(Lista *L1,int n){
    
    Lista *aux;
    Lista *anterior, *atual = L1;
    aux = (Lista*)malloc(sizeof(Lista));
    if(L1==NULL){
        aux->num = n;
        aux->prox = L1;
        L1 = aux;
    }
    else {while(atual!=NULL){anterior = atual;atual=atual->prox;}
    aux->num = n;
    aux->prox = anterior->prox;
    anterior->prox = aux;}
    return L1;
}

int contador(Lista *L){
    if(L==NULL) return 0;
    return 1+contador(L->prox);
}

Lista *manipulalista(Lista *L1, Lista *L2){

    Lista *aux1,*aux2;
    aux1 = L1;
    while(aux1!=NULL){
      aux2 = L2;
      L2 = L2->prox;
      aux2->prox = aux1->prox;
      aux1->prox = aux2;
      aux1= aux2->prox;
    }
    return L1;
}

void printar(Lista *L){
    Lista *aux = L;
    while(aux!=NULL){
        printf("%d",aux->num);
        printf("->");
        aux = aux->prox;
    }
    printf("NULL");
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
    
    Lista *L1;
    Lista *L2;
    
    L1 = NULL;
    L2 = NULL;
    
    int i,j,n;
    printf("Digite o numero de elemetos da lista 1 e lista 2: ");
    scanf("%d %d", &i,&j);
    
    while(i>0){
        printf("Digite o elemento: ");
        scanf("%d",&n);
        L1 = criaLista(L1,n);
        i--;
    }
    while(j>0){
        printf("Digite o elemento: ");
        scanf("%d",&n);
        L2 = criaLista(L2,n);
        j--;
    }
    printar(L1);
    printf("\n");
    printar(L2);
    printf("\n");
    L1 = manipulalista(L1,L2);
    printar(L1);
    destroi(L1);
    destroi(L2);
    
    return 0;
}
