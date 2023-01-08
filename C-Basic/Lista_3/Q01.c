#include <stdio.h>
#include <stdlib.h>
#define TAM 12
typedef struct {
  float salario;
  int idade;
  int filhos;
  }Familia;

void ler(Familia *pessoa){

    float mediaSalario = 0.0,maior = 0.0;
    int mediaFilhos = 0;
    for(int i=0;i<TAM;i++){

        printf("Digite o salario: ");
        scanf("%f",&pessoa[i].salario);
        mediaSalario += pessoa[i].salario;
        if(pessoa[i].salario>maior){
            maior = pessoa[i].salario;}

        printf("Digite a idade: ");
        scanf("%d",&pessoa[i].idade);

        printf("Digite o numero de filhos: ");
        scanf("%d",&pessoa[i].filhos);
        mediaFilhos += pessoa[i].filhos;
  }
  
  
    printf("A media de salario da populaçao eh: %f",mediaSalario/TAM);
    printf("\n A media do numero de filhos eh: %d",mediaFilhos/TAM);
    printf("\n O maior salario eh: %f",maior);
}
int main(){

  Familia p[TAM];

  ler(&p);
  return 0;
} 
