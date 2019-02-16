#include <stdio.h>
#include <stdlib.h>
#include "headers//ficha1.h"
#include "headers//ficha2.h"
#include "headers//outras.h"

#define TRUE  1
#define FALSE 0

int main(){
    int ficha,exercicio,flowControl;

    system("CLS");      
   
    GOTO_ESCOLHA_FICHA:
    ficha=escolhaFicha();
        
    GOTO_ESCOLHA_EXERCICIO:
    exercicio=escolhaExercicio(ficha);

    system("CLS");
    showTitle();

    flowControl = loadExercise(ficha,exercicio);

    printf("ANY KEY TO CONTINUE...");
    getchar();
    cleanInputBuffer();
    system("CLS");
    
    if(flowControl==1)               
        goto GOTO_ESCOLHA_FICHA;    

    if(flowControl==0){        
        showTitle();
        goto GOTO_ESCOLHA_EXERCICIO;
    }

    
    showTitle();
    getchar();
    system("CLS");
    return 0;
}
