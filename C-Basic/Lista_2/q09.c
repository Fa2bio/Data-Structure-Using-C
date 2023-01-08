#include <stdio.h>
#include <string.h>

int main(){

    int x;
    printf("Digite o numero: ");
    scanf("%d",&x);

    int matriz[x][x];
    char c;

    while(x>0){

        for (int i=1;i<x+1;i++){
            for (int j=1;j<x+1;j++){
                matriz[i-1][j-1]=i*j;
            }
        }

        printf("Deseja imprimir a matriz ?: ");
        scanf("%c",c);

        if (!(strcmp("-1",c))){

            printf("\n");
            for (int i=0;i<x;i++){
                for (int j=0;j<x;j++){
                    printf("%d",matriz[i][j]);
                    printf(" ");
                }
            printf("\n");
            }

        }

        printf("Digite o numero: ");
        scanf("%d",&x);
    }

return 0;

}

