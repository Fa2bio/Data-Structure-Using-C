#include <stdio.h>
#include <string.h>


void imprimi(char palavra[100]){

    if (palavra!='\0'){
        printf("%c",palavra[0]);
        imprimi(palavra[1]);
    }


}

int main(){

    char palavra[100];
    printf("%s","Digite a palavra ");
    scanf("%s",&palavra);
    imprimi(palavra[100]);

    return 0;
}
