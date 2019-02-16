#include <stdio.h>
#include "..//headers//ficha1.h"




//------------------------------------------------
// EXERCICIO 2
//------------------------------------------------

void f1Ex2(){
    int linha,coluna,altura;
    
    printf("Insira valor da altura desejada: ");
    scanf("%d",&altura);
    
    putchar('\n');
    for( linha=1 ; linha<=altura ; linha++ ){
        for (coluna=altura ; coluna>0 ; coluna--)
            putchar('#');
        putchar('\n');
    }
    putchar('\n');
}




//------------------------------------------------
// EXERCICIO 3
//------------------------------------------------

void f1Ex3(){
    int linha,coluna,altura;

    printf("Insira valor da altura desejada: ");
    scanf("%d",&altura);
    
    putchar('\n');
    for( linha=1 ; linha<=altura ; linha++ ){
        for (coluna=1 ; coluna<=altura ; coluna++)           
            if(!(coluna%2))
                putchar('_');
            else
                putchar('#');
        putchar('\n');
    }
    putchar('\n');
}




//------------------------------------------------
// EXERCICIO 4
//------------------------------------------------

void f1Ex4_triang1(){
    int linha,coluna,nHTags,altura;

    printf("Insira valor da altura desejada: ");
    scanf("%d",&altura);
    
    putchar('\n');
    for (linha=1 ;  ; linha++){
        
        if(linha<=altura)
            nHTags=linha;
        else
            nHTags--;
                
        for (coluna=nHTags ; coluna>0 ; coluna--)
            putchar('#');
        
        if (!nHTags)
            return;
        
        putchar('\n');               
    }
    putchar('\n');
}

void f1Ex4_triang2(){
    int linha,coluna,nHTags=1,nEspacos,altura;
    
    printf("Insira valor da altura desejada: ");
    scanf("%d",&altura);

    nEspacos=altura-1;

    putchar('\n');
    for (linha=1 ; linha<=altura; linha++){
        for (coluna=nEspacos ; coluna>0 ; coluna--)
            putchar(' ');
        for (coluna=nHTags ; coluna>0 ; coluna--)
            putchar('#');        
        putchar('\n');
        nEspacos--;
        nHTags+=2;       
    }
    putchar('\n');
}

