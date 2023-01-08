#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

///Protótipos
FILE* Abre(char caminho[30], char modo);
void Fechar(FILE *Arquivo);


FILE* Abre(char caminho[30], char modo){ //Esta função retorna um ponteiro do tipo FILE.
     FILE *Arquivo; //Um ponteiro chamado arquivo foi criado e está apontando para FILE

//Modos de abertura do :
    switch(modo){
        case 'g':
            Arquivo = fopen(caminho,"wt"); //"wt" - Para escrita no .
            break;
        case 'l':
            Arquivo = fopen(caminho,"rt"); // "rt" - Para ler o conteúdo do .
            break;
        case 'a':
            Arquivo = fopen(caminho,"a"); // "a" - Para acrescentar alguma informação no .
            break;
    }
    if(Arquivo==NULL){ //Se houver algum erro, o ponteiro apontará para NULL e uma msg informando o erro será exibida.
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return Arquivo;
}///End Abre

void Fechar(FILE *Arquivo){

    fclose(Arquivo);
}///End Fechar


















#endif // ARQUIVO_H_INCLUDED
