#include <stdio.h>

int mdc(int x, int y){

    if ((y<=x) && (x%y==0)){
        return y;
    }else if(x<y){
        return mdc(y,x);
    }else{
        return mdc(y,x%y);
    }
}

int main(){

    int x,y;
    printf("Digite dois numeros: ");
    scanf("%d %d",&x,&y);

    printf("%d",mdc(x,y));

    return 0;
}
