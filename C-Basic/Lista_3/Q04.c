 
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  char os[40];
  char servico[40];
  char nome[40];
  float valor;
  }Ordem;

int main(){
    int N;
    Ordem *p;
    float media = 0.0,maior = 0.0;
    char *s;
    printf("Digite a quantidade de ordens de servico: ");
    scanf("%d",&N);
    p = (Ordem*)malloc(N*sizeof(Ordem));
    
    for(int i=0;i<N;i++){
        
        printf("Digite o numero da ordem: ");
        scanf("%s",&*p[i].os);
        
        printf("Digite o valor: ");
        scanf("%f",&p[i].valor);
                
        printf("Digite o tipo de servico: ");
        scanf("%s",&*p[i].servico);
        
        printf("Digite o nome do cliente: ");
        scanf("%s",&*p[i].nome);
        
        printf("\n");
        media += p[i].valor/N;
        if(p[i].valor>maior) {
            maior = p[i].valor;
            s = p[i].nome;
        }
    }
    
    printf("\nA media dos servicos prestados eh: %f",media);
    printf("\nO cliente que pagou mais caro foi: %s",s);
    
    for(int i=0;i<N;i++){
        if(p[i].valor>media){
            printf("\nOs clientes que pagaram acima da media foram: %s",p[i].nome);
        }
    }
    
    return 0;
}
