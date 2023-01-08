#include <stdio.h>
#include <stdlib.h>


struct lista{
    int num;
    struct lista *prox;};
typedef struct lista Lista;

int pertence(Lista *L,int elem){
    if(L==NULL) return 0;
    else if(L->num == elem)return 1;
    return pertence(L->prox,elem);
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


void printar(Lista *L){
    while(L!=NULL){
        printf("%d ->",L->num);
        L = L->prox;
    }
    printf("\n");
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

Lista *inserirElemento(Lista *L,int n){
        Lista *aux;
        aux = (Lista*)malloc(sizeof(Lista));
        aux->num = n;
        aux->prox = L;
        L=aux;
        return L;
}

Lista *uniao(Lista *L1, Lista *L2){

    while(L2!=NULL){
        int n = L2->num;
        if(!pertence(L1,L2->num)){
            L1=inserirElemento(L1,n);
        }
        L2 = L2->prox;
    }
    return L1;
}

Lista *intersecao(Lista *L1,Lista *L2){
    Lista *L3;
    L3 = NULL;
    while(L2!=NULL){
        if(pertence(L1,L2->num)){
            L3 = inserirElemento(L3,L2->num);
        }
        L2 = L2->prox;
    }
    
    return L3;
}

Lista *diferenca(Lista *L1, Lista *L2){
    while(L2!=NULL){
        int n = L1->num;
        if(!pertence(L2,n)){
            L1=inserirElemento(L1,n);
        }
        L2 = L2->prox;
    }
    return L1;
}


int main(){

    Lista *L1, *L2, *L3;
    
    int taml1, taml2,esc , status =1, pert;

    do{
        L1 = NULL;L2 = NULL;L3 = NULL;
        printf("################################## \n");
        printf("Digite: 1-Uniao / 2-Intersecao / 3-Diferenca / 4-Pertinencia / 0-Sair");
        scanf("%d",&esc);
        
        if(esc == 0){
            status = 0;
        }else{
        
            printf("Digite o tamanho da lista 1: ");
            scanf("%d",&taml1);
                    
            while(taml1>0){
                inserir(&L1);
                taml1--;
            }
            
            printf("Digite o tamanho da lista 2: ");
            scanf("%d",&taml2);
            
            while(taml2>0){
                inserir(&L2);
                taml2--;
            }
            printf("\n");
    
            switch(esc){
                case 1:
                    L1 = uniao(L1,L2);
                    printf("\n");
                    printar(L1);
                    break;
                    destroi(L1);
                    destroi(L2);
                    
                case 2:
                    L1 = intersecao(L1,L2);
                    printf("\n");
                    if(L1 == NULL){
                        printf("Sem intersecao");
                        free(L1);
                    }else{
                        printar(L1);
                        destroi(L1);
                    }
                    destroi(L2);
                    
                    break;
                case 3:
                    printf("Digite 1 para A - B e 2 para B - A: ");
                    scanf("%d",&pert);
                    if(pert){L1 = diferenca(L1,L2);}
                    else if(pert==2){L1 = diferenca(L2,L1);}
                    printar(L1);
                    destroi(L1);
                    destroi(L2);
                    
                    break;
                case 4:
                    printf("Digite um numero: ");
                    scanf("%d",&pert);
                    
                    if(pertence(L1,pert)){printf("O numero pertence a lista 1");}
                    else printf("O numero nao pertence a lista 1");
                    
                    if(pertence(L2,pert)){printf("O numero pertence a lista 1");}
                    else printf("O numero nao pertence a lista 1");
                    
                    destroi(L1);
                    destroi(L2);
                    
                    break;
            }
            printf("\n");
        }    
    }while(status);
}
