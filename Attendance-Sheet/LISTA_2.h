#ifndef LISTA1_LNK_INCLUDED
#define LISTA1_LNK_INCLUDED
#endif // ESTRUTURA_LNK_INCLUDED
#include "LISTA_1.h"
#include<locale.h>

///Protótipos
void escreveTodos(lista * alunos);
int buscar(char comp[35]);
int alterar(char comp[35], lista *alunos );
int deletar(char comp[35]);


void escreveTodos(lista * alunos){
    while(alunos!=NULL){
        escreveArquivo(alunos,"w");
        alunos = alunos->prox;
    }
}

int buscar(char comp[35]){
    lista *p; //cria um ponteiro para a struct lista
    int v = 0; // variável de verificação, se for setada em 1(lista foi encontrado), 0(lista nào foi encontrado);
    p = inicio; // ponteiro p, do tpw lista, aponta para o primeiro elemento da lista(inicio).
    if(inicio == NULL){
        printf("Nao ha alunos cadastrados\n\n");
        return 0;
    }else{

        do{
            if(!strcmp(p->nome,comp))
            {
                /*strcmp, retorna 0, caso as string seja
                iguais,, o modificado !, altera, para q
                se sela sejam iguais, o retorno passe a
                ser 1 ao inves de 0. */
                v++; // incrementa v, q sera verificado posteriormente
                break;
            }///End if
            p = p->prox; // faz com q o ponteiro p aponte para a próxima struct q o campo prox esta indicando.
        }while(p != NULL);
    }///End else
    if(v > 0){  // > 0 como foi mencionado,, significa q lista procura foi encontrado.
        printf("Nome: %s\n", p->nome);
        printf("RA: %d\n" , p->ra);
        return 1; // retorna 1, foi encontrado
    }else{
        printf("Aluno nao encontrado.\n");
        return 0;
    }
}///End buscar

int alterar(char comp[35], lista *alunos ){ // usa o mesmo principio da funcao buscar,,
        FILE Arquivo;
        lista *p;
        int v = 0; // variável de verificação.
        p = inicio; // ponteiro p, do tpw client, aponta para o primeiro elemento da lista(inicio).
        if(inicio == NULL){
            printf("Nao há alunos cadastrados\n");
            return 0;
        }else {

            do {
                if(!strcmp(p->nome,comp)){
                    v=1;                                                                        // o break foi usado no if() logo quando a condição se torna verdade, isso garante q *p
                    break;                                                                      //  está ainda apontando para a struct da lista q o aluno  foi encontrado.
                }
                p = p->prox; // faz com q o ponteiro p aponte para a próxima struct
            printf("Alterar nome do aluno para: \n");
            }while(p != NULL);
        }
        if(v > 0){  // caso tenha sido encontrado,, permitie q o usuario entre com novos dados para o aluno.
            printf("Aluno: %s\n RA: %d\n", p->nome, p->ra);
            fflush(stdin);
            gets(p->nome);

            printf("Alterar RA do aluno para: \n");
            fflush(stdin);
            scanf("%d",&p->ra);
            escreveTodos(inicio);

            return 1;
        }else {
            printf("aluno nao encontrado.\n");
            return 0;
        }
}

int deletar(char comp[35]){

    int r = 0;
    lista *antes, *atual, *pass = NULL;
    antes = atual = inicio;
     if(inicio == NULL){
        printf("\nImpossivel completar esta acao.\n\n");
        return 0;
    }
    do{
        if(!strcmp(atual->nome,comp)){  // verifica se nome está na struct apontada por atual

            if (atual == inicio && ultimo == NULL){   // verifica se o q vai ser exlcuido eh o primeiro registro e unico da lista
                free(atual); // como eh o único registro, basta usar o free.
                inicio = NULL; // inicio agora recebe NULL;
                r = 1;
            }else if(atual == inicio){ // verifica se o q vai ser excluido eh o primeiro registro..

                inicio = atual->prox; /* como o atual esta apontando para inicio, antes
                                        de usar o free para esse ponteiro(atual), precisamos garantir
                                        q o inicio continue apontando para o topo da lista,
                                        e o topo da lista agora vai ser a struct q inicio
                                        esta apontando,, logo,, "dizemos" para q o ponteiro
                                        *inicio, aponte para a struct q está indicada pelo
                                        seu campo *prox */
                free(atual);
                r = 1; // serve para fazer uma verificação,, 1, foi excluído, 2, nào foi excluído.
                break;
            }else if (atual->nome == ultimo->nome){   // verifica se é o ultimo elemento da lista

                ultimo->prox = antes; /* garante q o ultimo prox agora aponte para struct
                                            antes(a struct q está apontando para ultimo), verificar
                                            fim do "do{}" para maiores detalhes. */
                antes->prox = NULL; /* antes passa a ser o ultimo,, por isso o campo antes
                                        agora vai ser alterado para NULL, antes, antes estava
                                        apontando para ultimo, sendo q ultimo vai ser deletado,
                                        opr isso antes vai passar a a pontar para null, */
                free(atual);
                r = 1;
                ultimo = antes;
                break;
            }else{   // usado quando o registro, não eh o ultimo, não eh o primeiro e não eh o único elemento da lista.
                pass = atual; // pass agora aponta para o mesma struct q atual esta apontando.
                pass = atual->prox; // pass passa a apontar para a struct q o campo prox está indicando.
                antes->prox = pass; /* antes prox, aponta para pass e pass não está + apontando para atual e
                                        sim para a struct q atual está apontando,, logo,,
                                        antes->prox q apontava para a struct atual passa a
                                        apontar para pass(q é a struct apontada por atual) */
                r = 1;
                free(atual);
                break;
            }
        }///end if_1
        else{
            antes = atual; // depois q esse bloco {} eh executado uma vez,, antes eh sempre a struct q aponta para a struct atual
            atual = atual->prox; // e atual aqui passa a apontar para a struct lista q o seu campo prox aponta
        }
    }while(antes != ultimo);
        if(r > 0)
            return 1;
        else
            return 0;
}///End deletar

void ajuda(){
    setlocale(LC_ALL, "Portuguese");
    printf("MENU - Apresentará 9 opções ao usuário, e cada opção terá sua funcionalidade. \nVeja a seguir...\n\n");
    printf("<1> - Criará um arquivo de texto chamado lista e adicionará um aluno de cada vez a esta lista.\n\n");
    printf("<2> - Iniciará a chamada dos alunos. Irá pedir para que o usuário insira o dia/mês/ano que a lista será criada.\n\n");
    printf("<3> - Irá listar os alunos que foram adicionados na opção <1>.\n\n");
    printf("<4> - Listará a situação dos alunos de acordo com o dia/mês/ano criado anteriormente na escolha da opção <2>.\n\n");
    printf("<5> - Buscará na lista criada anteriormente na opção <1>, o aluno que o usuário quer encontrar.\n\n");
    printf("<6> - Alterá o nome e/ou RA do aluno que estará na lista.\n\n");
    printf("<7> - Deletará o aluno escolhido pelo usuário, que se encontra na lista criada.\n\n");
    printf("<9> - Encerrará o programa, assim que solicitada.\n\n");

}
