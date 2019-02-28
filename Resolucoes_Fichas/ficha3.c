#include <stdio.h>
#include <stdlib.h>





//------------------------------------------------
// EXERCICIO 2
//------------------------------------------------

void swapM( int *x, int *y){
    int temp;

    temp=*x;
    *x=*y;
    *y=temp;
}




//------------------------------------------------
// EXERCICIO 3
//------------------------------------------------

void swap( int *v, int i, int j){
    int temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}




//------------------------------------------------
// EXERCICIO 4
//------------------------------------------------

int soma(int *v, int N){
    int soma=0;

    if(N<=0){
        printf("\n\n\n!!!!!??? ERRO ARGUMENTOS !!!!!?????\n\n\n");
        exit(1);
    }

    N--;
    while(N!=-1){
        soma+=v[N];
        N--;
    }

    return soma;
}



//------------------------------------------------
// EXERCICIO 5
//------------------------------------------------

int maximum( int *v , int N , int *m){
    int max;

    if(N<=0){
        printf("\n\n\n!!!!!??? ERRO ARGUMENTOS !!!!!?????\n\n\n");
        return 0;
    }

    N--;
    max=v[N];
    N--;

    while(N!=-1){
        max= ( v[N]>max ) ? v[N] : max;
        N--;
    }

    *m=max;

    return max;
}




//------------------------------------------------
// EXERCICIO 6
//------------------------------------------------

void quadrados ( int *q , int N){

    if(N<=0){
        printf("\n\n\n!!!!!??? ERRO ARGUMENTOS !!!!!?????\n\n\n");
        exit(1);
    }

    // Notas: - existem N naturais
    //        - indice para cada natural ao quadrado: N-1
    while( (N-1)!=-1 ){
        q[N-1]=N*N;
        N--;
    }
}




//------------------------------------------------
// EXERCICIO 7
//------------------------------------------------

// V contem a valores da linha anterior
void pascal ( int *v , int N ){
    int pascalAnterior[N], i;

    for ( i=0 ; i<N-1 ; i++)
        pascalAnterior[i]=v[i];
    
    for ( i=1 ; pascalAnterior[i-1]!=1 ; i++)
        v[i]=pascalAnterior[i-1]+pascalAnterior[i];
    
    v[i]=1;
    v[i+1]=0;
}

