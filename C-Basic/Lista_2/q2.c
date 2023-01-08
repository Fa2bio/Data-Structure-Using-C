#include <stdio.h>
#include <string.h>

int media(int notas[6]){ /* FUNÇAO RECEBE SEIS NOTAS*/

    int media=0,maior=0,menor=notas[0];

    for(int i=0;i<5;i++){
        if(notas[i]<notas[i++]){
            menor=notas[i++];
        }
        if(notas[i]>notas[i++]){
            maior=notas[i++];
        }
    }

    for(int i=0;i<6;i++){

        if(notas[i]!=maior && notas[i]!=menor){
            media+=notas[i];
        }

    }

    return media/4;

}

int main(){

    int notas[6];

    for(int i=0;i<30;i++){
        printf("%s %d %s","Digite as notas do atleta ",i+1,"\n");
        for(int j=0;j<6;j++){
            notas[j] = scanf("%d",&notas[j]);
        }
        printf("%s %d %s","A media deste atleta foi: ",media(notas),"\n");
    }

    return 0;
}
