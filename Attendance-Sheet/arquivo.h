#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

///Prot�tipos
FILE* Abre(char caminho[30], char modo);
void Fechar(FILE *Arquivo);


FILE* Abre(char caminho[30], char modo){ //Esta fun��o retorna um ponteiro do tipo FILE.
     FILE *Arquivo; //Um ponteiro chamado arquivo foi criado e est� apontando para FILE

//Modos de abertura do :
    switch(modo){
        case 'g':
            Arquivo = fopen(caminho,"wt"); //"wt" - Para escrita no .
            break;
        case 'l':
            Arquivo = fopen(caminho,"rt"); // "rt" - Para ler o conte�do do .
            break;
        case 'a':
            Arquivo = fopen(caminho,"a"); // "a" - Para acrescentar alguma informa��o no .
            break;
    }
    if(Arquivo==NULL){ //Se houver algum erro, o ponteiro apontar� para NULL e uma msg informando o erro ser� exibida.
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return Arquivo;
}///End Abre

void Fechar(FILE *Arquivo){

    fclose(Arquivo);
}///End Fechar


















#endif // ARQUIVO_H_INCLUDED
