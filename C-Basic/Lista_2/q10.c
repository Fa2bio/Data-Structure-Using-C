#include <stdio.h>
#define TAM 2

typedef struct {
    char nome[40];
    float notaUm,notaDois,notaTres,notaQuatro,media;
    int ano;
} Alunos;

void imprimir(Alunos *aluno){
    for (int i=0;i<TAM;i++){
        printf("%s \n",aluno[i].nome);
    }
}

void ler(Alunos *aluno){

    float x;

    for(int i=0;i<TAM;i++){
        printf("Digite o nome do aluno: ");
        scanf("%s",&aluno[i].nome);

        printf("Digite a nota um: ");
        scanf("%f",&aluno[i].notaUm);

        printf("Digite a nota dois: ");
        scanf("%f",&aluno[i].notaDois);

        printf("Digite a nota tres: ");
        scanf("%f",&aluno[i].notaTres);

        printf("Digite a nota quatro: ");
        scanf("%f",&aluno[i].notaQuatro);

        printf("Digite o ano de ingresso na faculdade: ");
        scanf("%d",&aluno[i].ano);

        printf("\n");

        x = aluno[i].notaUm + aluno[i].notaDois + aluno[i].notaTres + aluno[i].notaQuatro;
        aluno[i].media = x/4;

    }

}

void media(Alunos *aluno){

    float x;
    for (int i=0;i<TAM;i++){
        if(aluno[i].media > x){
            x = aluno[i].media;
        }
    }
    printf("%f \n",x);
    for (int i=0;i<TAM;i++){
        if(aluno[i].media == x){
            printf("O aluno de maior media: %s \n",aluno[i].nome);
        }
    }

}


int main(){

    Alunos aluno[TAM];
    ler(&aluno);
    media(&aluno);

return 0;
}
