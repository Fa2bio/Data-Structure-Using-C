#ifndef LISTA1_LNK_INCLUDED
#define LISTA1_LNK_INCLUDED
#include "arquivo.h"
#include <string.h>
#include <ctype.h>

///Estrutura
typedef struct lista_chamada{
    char nome[35];
    int ra;
    char op;
    struct lista_chamada *prox; //Ponteiro chamado prox, que aponta para a struct lista_chamada
}lista;
 lista *inicio=NULL, *ultimo=NULL, *novo=NULL;// cria 3 ponteiros que iram apontar para a struct lista_chamada

///Protótipos
void carregaArquivo();
void escreveArquivo(lista *aluno, char* tipo);
void insereUm(lista * aluno);
int inserir();
int cadastrado(char nome[35], int k);
int chamada();
void listar();
char *digitarData();
void imprimeLista(lista* alunos);
void listarsituacao();


int cadastrado(char nome[35], int k);//Declarada como global, porque é utilizada em outras funções

void carregaArquivo(){
    char ch;
    int flag=0;
    int num=0;
    int i,RA;
    char   ra[15];
    FILE *arquivo;
    arquivo = Abre("lista.prn", 'l');

        lista *aluno;
        for(num=0,i=0; (ch=fgetc(arquivo))!= -1; i++){ //Este for se repetirá, até que
            switch(num){
                case 0:
                    if(flag==0){
                        aluno=(lista*)malloc(sizeof(lista));
                        memset(aluno->nome,0x0,sizeof(char[35]));
                        flag=1;
                    }
                    aluno->nome[i]=ch;
                break;
                case 1:
                    if(flag==0){
                        memset(ra,0x0,sizeof(char[15]));
                        ra[i]=ch;
                        flag=1;
                    }
                ra[i]=ch;
                break;
            }//End switch
            if(ch == '\n' || ch == '\0'){

                switch(num){
                    case 0:
                        aluno->nome[i]='\0';
                    break;
                    case 1:
                        ra[i]='\0';
                        RA=atoi(ra);
                        aluno->ra=RA;
                        insereUm(aluno);
                        num=-1;
                    break;
                }//End switch2
                num++;
                flag=0;
                i=-1;
            }
        }
    Fechar(arquivo);
}

void escreveArquivo(lista *aluno, char* tipo){

    FILE *arquivo ;
    arquivo=fopen("lista.prn",tipo);
    if(arquivo==NULL){
        perror("Erro ao escrever no arquivo");
    }
    else{
        fprintf(arquivo,"%s\n%d\n",aluno->nome,aluno->ra);
        fclose(arquivo);
    }
}

void insereUm(lista *aluno){

    aluno->prox = NULL; // garante q o campo prox da struct lista esteja NULL
    if(inicio == NULL) /*verifica se o ponteiro para o primeiro elemento da lista foi setado
                            caso esse if seja verdadeiro, então significa q o ponteiro para a
                            'cabeça'(primeiro elemento) não foi setado, sendo assim, esses
                            dados q foram inseridos ainda agora passam a ser apontados pelo
                            ponteiro(do tipo struct) *inicio(q tem escopo global). */
    {
        inicio = aluno; // atribui um valor para ser o primeiro elemento da lista.
        ultimo = inicio; // atribui para q o *ultimo aponte para inicio;
    }
    else{    // caso o ponteiro inicio nào seja null, logo significa q inicio jah está apontando para o primeiro elemento da lista.


        ultimo->prox = aluno; /* caso esteja sendo a segunda vez q vc chamou essa função,
                                    o ponteiro ultimo continua apontando para a mesma struct
                                    que o ponteiro inicio aponta, sendo assim, mudamos o valor
                                    da primeira struct q foi criar para apontar para a nova struct
                                    q acabou de ser criada */
        aluno->prox = NULL; /* garantimos q a struct q acabo de ser criada vai apontar
                                para um valor null, indicando ser o ultimo elemento da lista */
        ultimo = aluno; // as ultimas informacoes digitas são atribuidas ao ponteiro ultimo q tem escopo global,,
    }///End else
}

int inserir(){

    lista *p; //Ponteiro dentro da função inserir que aponta para a struct(escopo dele se resume a essa funcao),quando a função é finalizada, ele deixa de existir, ao contrario dos outros 3 (inicio, ultimo e novo).
    novo = (lista *)malloc(sizeof(lista)); // armazena espaço na memória para a nova struct.

    if(novo == NULL){   //Se a alocação de memória para novo falhar, ele será NULL e uma msg de erro será exibida.
        printf("Erro ao tentar alocar memoria.\n");
    }else{   // Se não falhar, este bloco de comandos será executados.
        printf("Digite o nome do novo aluno: ");
        fflush(stdin);
        gets(novo->nome);
        printf("Digite o RA do aluno: ");
        scanf("%d", &novo->ra);
        if(cadastrado(novo->nome, novo->ra) == 1){
            printf("Erro ao tentar cadastrar aluno.\nNome ou RA ja estao em uso.\n");
            return 0;
        }
        escreveArquivo(novo,"a");
        novo->prox = NULL; // garante q o campo prox da struct lista esteja NULL
        if(inicio == NULL) /*verifica se o ponteiro para o primeiro elemento da lista foi setado
                            caso esse if seja verdadeiro, então significa q o ponteiro para a
                            'cabeça'(primeiro elemento) não foi setado, sendo assim, esses
                            dados q foram inseridos ainda agora passam a ser apontados pelo
                            ponteiro(do tipo struct) *inicio(q tem escopo global). */
        {
            inicio = novo; // atribui um valor para ser o primeiro elemento da lista.
            ultimo = inicio; // atribui para q o *ultimo aponte para inicio;
        }
        else{    // caso o ponteiro inicio nào seja null, logo significa q inicio jah está apontando para o primeiro elemento da lista.

            ultimo->prox = novo; /* caso esteja sendo a segunda vez q vc chamou essa função,
                                    o ponteiro ultimo continua apontando para a mesma struct
                                    que o ponteiro inicio aponta, sendo assim, mudamos o valor
                                    da primeira struct q foi criar para apontar para a nova struct
                                    q acabou de ser criada */
            novo->prox = NULL; /* garantimos q a struct q acabo de ser criada vai apontar
                                para um valor null, indicando ser o ultimo elemento da lista */
            ultimo = novo; // as ultimas informacoes digitas são atribuidas ao ponteiro ultimo q tem escopo global,,
        }///End else_2
    }///End else
    return 1;
}///End Inserir

int cadastrado(char comp[35], int k){

    lista *p; //cria um ponteiro para a struct lista
    int v = 0; // variável de verificação, se for setada em 1(lista foi encontrado), 0(lista nào foi encontrado);
    p = inicio; // ponteiro p, do tipo lista, aponta para o primeiro elemento da lista(inicio).
    if(inicio != NULL){
        do{
            if(!strcmp(p->nome,comp) || p->ra == k){
                v++;
                break;
            }
            p = p->prox; // faz com q o ponteiro p aponte para a próxima struct q o campo prox esta indicando.
        }while(p != NULL);
    }///End if
    if(v > 0){
        return 1; // retorna 1, foi encontrado
    }else {
        return 0;
    }
}///End cadastrado

int chamada(){

    FILE *arquivo;
    lista *p;
    char opcao;
    p = inicio;

    if(inicio == NULL){
        printf("\nNao ha alunos adicionados.\n\n\n");
        return 0;
    }
    else{
        arquivo = Abre(digitarData(), 'g');
        printf("\t======================================================\n");
        printf("\t|                   LISTA DE CHAMADA                 |\n");
        printf("\t======================================================\n\n\n");

        printf("\nDigite <P> para Presente ou <A> para Ausente\n\n\n");

        do{
            printf("%s - %d\n", p->nome, p->ra);
            fprintf(arquivo, "%s - %d____", p->nome, p->ra);
            printf("Situacao: ");
            fflush(stdin);
            scanf("%c",&opcao);

            if(tolower(opcao) == 'p')
                fprintf(arquivo, "PRESENTE \n");
                p->op=opcao;
            if(tolower(opcao) == 'a')
                fprintf(arquivo, "AUSENTE\n");
                p->op=opcao;
                p = p->prox;
        }while(p != NULL);
    }///end else
    Fechar(arquivo);
}

void listar(){

    char c;
    FILE *arquivo;
    arquivo = Abre("lista.prn", 'l');
    lista *p; //cria um ponteiro para a struct lista
    p = inicio; //o ponteiro p agora aponta para o mesmo local q o *inicio está apontando.
    if(arquivo == NULL)  // se algum usuário jah foi adicionado
        printf("Nao há alunos adicionados\n");

    imprimeLista(inicio);

}

char *digitarData(){
    char dia[3],mes[3],ano[5];
    char *nome =(char*)malloc(sizeof(char[20]));

    memset(nome,0x0,sizeof(char[20]));
    printf("Para iniciar ou buscar por uma lista de chamada, digite um o dia, mes e ano.\n\n");

    printf("Dia: ");
    fflush(stdin);
    scanf("%2s",&dia);

    printf("Mes: ");
    fflush(stdin);
    scanf("%2s",&mes);

    printf("Ano: ");
    fflush(stdin);
    scanf("%4s",&ano);

    dia[2]='\0';
    mes[2]='\0';
    ano[4]='\0';

    strcat(nome,dia);
    strcat(nome,mes);
    strcat(nome,ano);
    strcat(nome,".prn");
    if(nome[strlen(nome)-1]=='\0'){
       nome[strlen(nome)-1]=' ';
    }
    system("cls");
    return nome;

}

void imprimeLista(lista* alunos){

    while(alunos !=NULL){
        printf(" %s  - %d\n",alunos->nome,alunos->ra);
        printf("-----------------------------------------------------\n\n");
        alunos=alunos->prox;
    }
    printf("\n\n");
}


void listarsituacao(){

    FILE *arquivo;
    arquivo = Abre(digitarData(), 'l');
    lista *p;
    p = inicio;
    char c;

    if(arquivo == NULL){
        printf("Nao há chamada desse dia\n");
    }else{
        printf("\t================= SITUACAO ================\n\n");

        while((c = fgetc(arquivo)) != EOF ){
            printf("%c", c);
        }

        Fechar(arquivo);
    }///end else
    system("pause");

}///End listarsituação
#endif // ESTRUTURA_LNK_INCLUDED
