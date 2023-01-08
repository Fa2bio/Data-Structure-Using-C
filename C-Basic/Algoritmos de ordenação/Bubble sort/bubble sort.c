#include <stdio.h>
int main (){
    int vetor[5] = {0,2,9,1,5};
    int i, j,aux = 0;


    for (i = 0; i < 5; i++){
        for (j = i; j < 5; j++){
            if (vetor[j]<vetor[i]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;}
            }

        }
    for (i = 0; i < 5; i++){
        printf ("%d",vetor[i]);
    }

        return 0;
    }
