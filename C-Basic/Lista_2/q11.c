#include <stdio.h>
#define TAM 2

typedef struct {
    double x,y;
} Ponto;

void soma(Ponto *p){
    double sumX,sumY;
    for (int i=0;i<TAM;i++){
        sumX += p[i].x;
        sumY += p[i].y;
    }

    printf("%lf",sumX);
    printf("%lf",sumy);
}

void sub(Ponto *p){
    double somaX,somaY;
    for (int i=TAM-1;i>-1;i++){
        somaX += p[i].x;
        somaY += p[i].y;

        if(i==2){
            somaX -= p[i].x;
            somaY -= p[i].y;
        }
    }
    printf("%lf",somaX);
    printf("%lf",somay);
}

void pesquisar(Ponto *p){
    double x,y;
    printf("Digite as coordenadas");
    scanf("%lf %lf",&x,&y);
    /*for (int i=0;i<TAM;i++){


    }*/
}

void mostrar(Ponto *p){
    for (int i=0;i<TAM;i++){
        printf("%lf",p[i].x);
        printf("%lf",p[i].y);
    }
}
void ler(Ponto *p){

    for(int i=0;i<TAM;i++){
        printf("Digite o ponto X: ");
        scanf("%lf",&p[i].x);

        printf("Digite o ponto Y: ");
        scanf("%lf",&p[i].y);

    }

}


int main(){

    int x;
    Ponto p[TAM];

    ler(&p);
    printf("Digite 1 p/ somar,2 p/ subtrair, 3 p/ pesquisar, 4 p/ mostrar, 5 p/ sair do programa: ");

    do{

        switch (x){
            case 1: soma(&p);break;
            case 2: sub(&p);break;
            case 3: pesquisar(&p);break;
            case 4: mostrar(&p);break;
        }
    }while(x!=5);


return 0;
}
