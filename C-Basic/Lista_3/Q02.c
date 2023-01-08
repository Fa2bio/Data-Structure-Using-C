#include <stdio.h>
#include <stdlib.h>
#define TAM 20
typedef struct {
  char sigla[10];
  int veiculos;
  int acidentes;
  }Estatistica;

void ler(Estatistica *dados,int *porcent, char **a,char **b){

    int maior = 0, total = 0;
    float aci,vei;
    for(int i=0;i<TAM;i++){
        
        printf("Digite a sigla do estado: ");
        scanf("%s",&*dados[i].sigla);
        
        printf("Digite o numero de veiculos: ");
        scanf("%d",&dados[i].veiculos);

        printf("Digite o numero de acidentes: ");
        scanf("%d",&dados[i].acidentes);
        total += dados[i].acidentes;
        
        if(dados[i].veiculos>maior){
            maior = dados[i].veiculos;
            *a = dados[i].sigla;
        }

        aci = dados[i].acidentes;
        vei = dados[i].veiculos;

        if(i==0){
            *porcent = ((aci/vei)*100);
            *b = dados[i].sigla;
        }else{
            if(((aci/vei)*100) > (*porcent)){
                *porcent = ((aci/vei)*100);
                *b = dados[i].sigla;
            }
        }

  }
    printf("\nO estado com maior numero de carros eh: %s",*a);
    printf("\nO estado que posssui maior numero de acidentes eh: %s",*b);
    printf("\nO total de acidentes eh: %d",total);
}
int main(){

    Estatistica *p;
    p = (Estatistica*)malloc(TAM*sizeof(Estatistica));
    int *porcent;
    char *s,*w;
    ler(&p,&porcent,&s,&w);
    return 0;
} 
