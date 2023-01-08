#include <stdio.h>
#include <string.h>

int ocorrencia(char palavra[40],char frase[400]){

    int pos_b=0; /*GUARDA A POSICAO (NA FRASE) DA OCORRENCIA DOS CARACTERES DA PALAVRA*/
    int tamanho_palavra = strlen(palavra); /*ANALISA O TAMANHO DA PALAVRA*/
    int tamanho_frase = strlen(frase);/*ANALISA O TAMANHO DA FRASE*/
    int contador = 0;

    for(int i=0;i<tamanho_palavra && palavra[i]!="\0";i++){ /*PERCORRE A PALAVRA CARACTERE POR CARACTERE*/
        for(int j=pos_b;j<tamanho_frase && frase[j]!="\0";j++){/*PERCORRE A FRASE, BASEANDO-SE NA POSIÇAO DO ELEMENTO DA PALAVRA NA FRASE */
                if (palavra[i] == frase[j]){ /*CASO ACHE A PRIMEIRA OCORRENCIA, A POSIÇÃO EH ATUALIZADA, CONTADOR DE OCORRENCIAS INCREMENTADO, PARA E VAI PARA O PROXIMO ELEMENTO DA PALAVRA*/
                    pos_b = j;
                    contador += 1;
                    break;
                }
        }
    }
    if (contador==tamanho_palavra){ /*CASO O TAMANHO DA PALAVRA SEJA IGUAL AO CONTADOR, PALAVRA OCORRE EM FRASE, SE FOR MENOR OU MAIOR PALAVRA NÃO OCORRE TOTALMENTE EM FRASE*/
        return 1;
    }else{return 0;}
}

int main(){

    char palavra[40];
    char frase[400];

    printf("Digite a palavra: ");
    scanf("%s",palavra);

    scanf("%*[^\n]"); scanf("%*c"); /*LIMPA O BUFFER*/
    printf("Digite a frase: ");
    scanf("%[^\n]",frase);

    if(ocorrencia(palavra,frase)){
        printf("A ocorre dentro de B");
    }else{
        printf("A nao ocorre dentro de B");
    }
return 0;
}
