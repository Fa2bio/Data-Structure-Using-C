#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Dma;


void diferenca(Dma *dataUm){

    for(int i=0;i<2;i++){
        scanf("%d",dataUm[i].dia);
        scanf("%d",dataUm[i].mes);
        scanf("%d",dataUm[i].ano);
    }

    int dia,mes,ano;
    dia = dataUm[1].dia - dataUm[0].dia;
    mes = dataUm[1].mes - dataUm[0].mes;
    ano = dataUm[1].ano - dataUm[0].ano;

}


int main(){

    Dma dataUm[2];
    diferenca(&dataUm);

return 0;
}
