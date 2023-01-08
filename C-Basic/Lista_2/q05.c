#include <stdio.h>

void imprimi(int i,int j, int k){

    if (i<j && i+k!=j){
        printf("%d \n",i+k);
        return imprimi(i+k,j,k);
    }

}

int main(){

    int i,j,k;

    printf("Digite a faixa de numeros: ");
    scanf("%d %d",&i,&j);

    printf("Digite o k: ");
    scanf("%d",&k);

    imprimi(i,j,k);

    return 0;
}
