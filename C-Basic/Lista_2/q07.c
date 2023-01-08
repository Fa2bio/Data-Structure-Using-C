#include <stdio.h>


int imprimi(int *x,int *y){

    if (x>0){
        return 1 + imprimi(&x-&y,&y);
    }


}

int main(){

    int x,y;
    printf("%s","Digite dois numeros ");
    scanf("%d %d",&x,&y);
    printf("%d \n",imprimi(&x,&y));
    printf("%d",x);

    return 0;
}
