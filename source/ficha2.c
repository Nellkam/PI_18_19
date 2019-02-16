#include <stdio.h>
#include "..//headers/ficha2.h"




//------------------------------------------------
// EXERCICIO 1
//------------------------------------------------

float multInt (int nTimes, float num){ 
    float soma=0;
    // soma=r *enunciado*
    // nTimes=n ; num=m *enunciado*

    while(nTimes){ 

        if(nTimes>0){
            soma+=num;
            nTimes--;
        }            
        else {
            soma-=num;
            nTimes++;
        }

    }
    
    return soma;
}




//------------------------------------------------
// EXERCICIO 2
//------------------------------------------------

float f2Ex2 (int nTimes, float num){
    float soma=0;
        
    while(nTimes){         
        
        if(nTimes%2){
            if(nTimes>0)
                soma+=num;
            else
                soma-=num;
        }        
        
        nTimes=nTimes/2;
        num=num*2.0;
    }

    return soma;
}




//------------------------------------------------
// EXERCICIO 3
//------------------------------------------------

int mdc (int a, int b){
    int menorNum,maiorNum,maiorDivisor,divisor;

    if(a<0 || b<0){
        printf("\nArgumentos Invalidos! Apenas numeros inteiros positivos!\n");
        return 0;
    }

    menorNum = (a<b) ? a : b;
    maiorNum = (a>b) ? a : b;
    
    for(divisor=1 ; divisor<=menorNum ; divisor++){
        if( !(menorNum%divisor) && !(maiorNum%divisor) )
            maiorDivisor=divisor;        
    }
    
    return maiorDivisor;
}



//------------------------------------------------
// EXERCICIO 4
//------------------------------------------------

int mdc2 (int a,int b){
    int menorNum,maiorNum,newNum;

    menorNum = (a<b) ? a : b;
    maiorNum = (a>b) ? a : b;
    
    while(menorNum){
        newNum=maiorNum-menorNum;
        
        if(newNum<menorNum){
            maiorNum=menorNum;
            menorNum=newNum;
        }
        else
            maiorNum=newNum;
        
    }

    return maiorNum;
}




//------------------------------------------------
// EXERCICIO 5
//------------------------------------------------

int mdc3 (int a,int b){
    int menorNum,maiorNum,newNum;

    menorNum = (a<b) ? a : b;
    maiorNum = (a>b) ? a : b;
    
    while(menorNum){
        newNum=maiorNum%menorNum; // <----- alteracao
        
        if(newNum<menorNum){
            maiorNum=menorNum;
            menorNum=newNum;
        }
        else
            maiorNum=newNum;
        
    }

    return maiorNum;
}




//------------------------------------------------
// EXERCICIO 6a
//------------------------------------------------

int f2Ex6a(int n){
    if (n==1 || n==2)
        return 1;
    
    return f2Ex6a(n-2)+f2Ex6a(n-1);
}




//------------------------------------------------
// EXERCICIO 6b
//------------------------------------------------

int f2Ex6b(){
    int anterior1=1, anterior2=1, soma=0, fibPos,n;

    printf("Insira valor de uma posicao na sequencia Fibonacci: ");
    scanf("%d",&n);
    
    fibPos=n;
    
    while(n){
        if(n==fibPos || n==fibPos-1)
            soma=1;
        else {
            soma=anterior1+anterior2;
            anterior1=anterior2;
            anterior2=soma;            
        }
        n--;        
    }

    printf("Fibonacci = %d\n\n",soma);
    return soma;
}
