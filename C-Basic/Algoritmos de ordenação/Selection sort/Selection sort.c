#include <stdio.h>
int main (){
    int vetor[5];
    int i, j,pos;
    for (i = 0; i < 5;i++){
        scanf ("%d",&vetor[i]);
    }

    for (i = 0; i < 5; i++){
        for (j = i; j < 5; j++){
            if (vetor[j]<vetor[i]){
               pos = j;};
            }
        int aux;
        aux = vetor[pos];
        vetor[pos] = vetor[i];
        vetor[i] = aux;
        }
            for (i = 0; i < 5; i++){
        printf ("%d",vetor[i]);
    }

        return 0;
    }

