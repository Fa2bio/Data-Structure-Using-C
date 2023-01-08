#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#define TAM 2

typedef struct {
  char cor[5];
  float altura;
  int idade;
  }Carac;

int main(){
    
    Carac *p;
    p = (Carac*)malloc(TAM*sizeof(Carac));
    float maior=0.0,menor = FLT_MAX,media = 0.0;
    int cas = 0;
    for(int i=0;i<TAM;i++){
        
        printf("Digite a altura: ");
        scanf("%f",&p[i].altura);
        
        printf("Digite a idade: ");
        scanf("%d",&p[i].idade);
                
        printf("Digite a cor dos olhos: ");
        scanf("%s",&*p[i].cor);
        
        media += p[i].idade/(float)TAM;
        if(p[i].altura>maior) {
            maior = p[i].altura;
        }
        if(p[i].altura<menor){
            menor = p[i].altura;
        }
        printf("\n");
    }
    
    printf("\nA media das idades eh: %f",media);
    printf("\nA maior altura eh: %f",maior);
    printf("\nA menor altura eh: %f",menor);
    for(int i=0;i<TAM;i++){
        if((float)p[i].idade>media && !(strcmp(p[i].cor,"c"))){
          printf("a");
            cas++;
        }
    }
    printf("\nA quantidade de pessoas de olhos castanhos com idade>media eh: %d",cas);
    
    return 0;
} 
