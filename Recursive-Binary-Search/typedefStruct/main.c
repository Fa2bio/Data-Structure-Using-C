#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
        char nome[40]; // primeiro nome
        float notaF; // nota final
    } Aluno;

int pesquisaBin(int a, int b, float n, Aluno v[]);

void ordena(int tam, Aluno v[]){
    int i, j;
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            int res = strcmp(v[i].nome, v[j].nome);
            if(res > 0){ // res -1, 0 ou 1
                Aluno temp;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

#define NAO_ACHOU -1

int pesquisaSeq(int a, int b, int n, int v[]){
    int i;
    for(i=a;i<=b;i++){
        if(n==v[i]){
            return i;
        }
    }
    return NAO_ACHOU;
}

#define ACABOU -1
int lerAluno(Aluno *p){
    printf("digite nome do aluno ou fim ");
    scanf("%s", (*p).nome); // p->nome
    if ( strcmp(p->nome, "fim") == 0){
        return ACABOU;
    }
    printf("digite a nota final do aluno ");
    float temp;
    scanf("%f", &temp); //scanf("%f", &p->notaF);
    (*p).notaF = temp;
    return 0;
}

int main(){
    //Exercicio:
    // Fazer um programa para ler um conjunto
    // de nomes de alunos e suas notas finais
    // ordenar e fazer a pesquisa binaria de
    // uma certa nota
    Aluno v[1000] ;
    Aluno umCara;
    int i=0;

    // digite os dados do 1o aluno
    int resultado = lerAluno(&umCara);
    // enquanto nome diferente de fim
    while (resultado != ACABOU){
        v[i] = umCara;
        i++;
        // ler o proximo aluno
        resultado = lerAluno(&umCara);
    }

    int tam = i;
    // ordernar os alunos por nota
    ordena(tam, v);

    for(i=0;i<tam;i++){
        printf("nome %s nota %f\n", v[i].nome, v[i].notaF);
    }

    int res = pesquisaBin(0, tam-1, 10.0, v);
    if (res != NAO_ACHOU ){
        printf("%s tirou %f\n",
                    v[res].nome,
                    v[res].notaF
               );
    }


    /*


    // pesquisar se um existe aluno com nota tal
    float nota = 8.8;
    int resultado = pesquisaBin(0, tam-1, nota, v);
    if (resultado == NAO_ACHOU){
        printf("nao encontrado no vetor\n");
    } else {
        printf("esta na posicao %i\n", resultado);
    }
    */
    return 0;
}




int pesquisaBin(int a, int b, float n, Aluno v[]){
    // o vetor tem que estar ordenado
    // forma recursiva
    if (a>b)
        return NAO_ACHOU;
    int meio = (a+b)/2;
    if (v[meio].notaF == n)
        return meio;
    if (n < v[meio].notaF)
        pesquisaBin(a, meio-1, n, v);
    else
        pesquisaBin(meio+1, b, n, v);

    /* forma normal
    while (a <= b){
        int meio = (a+b)/2;
        if (v[meio].notaF == n){
            return meio;
        } else if (n < v[meio].notaF){
            b = meio -1;
        } else {
            a = meio + 1;
        }
    }
    return NAO_ACHOU;
    */
}

