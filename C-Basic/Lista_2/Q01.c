#include <stdio.h>
#include <string.h>


int palindromo(char *palavra){
    
    int inicio, fim, tamanho,verdade = 1;
    tamanho = strlen(palavra);

    for (inicio=0,fim = tamanho-1;fim>0&&palavra[inicio]!="\0";inicio++, fim--){
        if(palavra[inicio]!=palavra[fim]){
            verdade = 0;
            return verdade;
        }
    }
    return verdade;
    
    
}
int main(){
    char palin[40];
    printf("Digite a palavra: ");
    if(palindromo(palin)){
        printf("Verdade");
    }else printf("Falso");

    return 0;
} 
