struct pilha{
    int n;
    int tamanho;
    int *vetor;};
typedef struct pilha Pilha;


void push(Pilha *p, int topo, int x){
    if(p->n==*topo){
        *topo+=1;
        p->vet = realloc(p->vet,1+sizeof(p->vet));
    }
    p->n++;
    p->vet[p->n-1] = x;
}

void parimpar(Pilha *par,Pilha*impar,Pilha *p){
    
    
}

void pop(Pilha *p, int topo){

  if(!p->n){
    exit(1);
  }else{
    printf("\n %d",p->vet[p->n-1]);
    p->n--;
  }
}

int main(){
    
    
    
    
    return 0;
}
