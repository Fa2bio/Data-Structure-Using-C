#include <stdio.h>
#include <stdlib.h>
typedef struct {
  float salario;
  float vendas;
  }Funcionario;

int main(){
    int N;
    Funcionario *p;
    float total;
    printf("Digite o numero de funcionarios: ");
    scanf("%d",&N);
    p = (Funcionario*)malloc(N*sizeof(Funcionario));
    
    for(int i=0;i<N;i++){
        
        printf("Digite o salario do funcionario: ");
        scanf("%f",&p[i].salario);
        
        printf("Digite o valor das vendas: ");
        scanf("%f",&p[i].vendas);
        
        total = p[i].salario + ((p[i].vendas)*((float)6/100));
        printf("O salario deste funcionario eh: %f",total);
        printf("\n");

    }
    
    return 0;
} 
