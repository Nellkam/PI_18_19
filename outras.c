#include <stdio.h>
#include <stdlib.h>
#include "..//headers//outras.h"
#include "..//headers//ficha1.h"
#include "..//headers//ficha2.h"

void cleanInputBuffer(){
    while( getchar() != (int)'\n' );
}

void showTitle(){    
    printf("============================================================================\n");
    printf("\t\tFICHAS PROGRAMACAO IMPERATIVA 18/19\n");
    printf("============================================================================\n\n");
    printf("\t\t\t\t\t\t\tBy Manuel Carvalho\n\n");
}

void showFichas(){
    puts("Escolha a Ficha:");
    puts("< 1 > Ficha 1");
    puts("< 2 > Ficha 2");
    printf("-> ");
}

void showExsFicha(int ficha){
    printf("Escolha o exercicio:\n\n");
    puts("< -1 > Terminar Programa");
    puts("< 0 > Mudar de Ficha\n");
    switch (ficha){
        case 1:
            puts("< 2 > Quadrado #");
            puts("< 3 > Quadrado #/_");
            puts("< 4 > Triangulos #");            
            break;
        case 2:
            puts("< 1 > Produto 2 numeros");            
            puts("< 2 > Produto 2 numeros (alternativa)");            
            puts("< 3 > Maximo divisor comum");            
            puts("< 4 > Maximo divisor comum (alternativa)");            
            puts("< 5 > Maximo divisor comum (alternativa 2)");            
            puts("< 6 > Fibonacci");            
            break;
        default:
            system("CLS");
            puts("$$$$$$$ FALTA DE ARGUMENTOS FUNÇAO showExsFicha $$$$$???");
            exit(1);
    }
    printf("-> ");
}

int escolhaFicha (){
    int ficha=-1;

    while(ficha!=1 && ficha!=2){       
        showTitle();
        showFichas();    
        scanf("%d",&ficha);
        cleanInputBuffer();
        if(ficha!=1 && ficha!=2)
            system("CLS"); 
    }
    
    return ficha;
}

int validExercise(int ficha,int exercicio){
    switch (ficha){
        case 1:
            return exercicio==2 || exercicio==3 || exercicio==4 || exercicio==0 || exercicio==-1;
        case 2:
            return exercicio==1 || exercicio==2 || exercicio==3 || exercicio==4 || exercicio==5 
                    || exercicio==6 || exercicio==0 || exercicio==-1;
        default:
            system("CLS");
            system("CLS");
            puts("$$$$$$$ FALTA DE ARGUMENTOS FUNÇAO validExercise() $$$$$???");
            exit(1);
    }
}

int escolhaExercicio(int ficha){
    int exercicio=666;
    
    putchar('\n');
    while(1){    
        showExsFicha(ficha);
        scanf("%d",&exercicio);
        cleanInputBuffer();

        if( validExercise(ficha,exercicio) )
            break;
        
        system("CLS");
        showTitle();
    }
    
    return exercicio;
}

// return 0 -> continuar mesma ficha 
// return 1 -> muda de ficha
// return -1 -> terminar programa
int loadExercise(int ficha,int exercicio){
    int num1,num2;
    float numfl1;

    if(ficha==1)
        switch (exercicio){
            case 0:
                return 1;
            case -1:
                return -1;
            case 2:
                f1Ex2();
                break;
            case 3:
                f1Ex3();
                break;
            case 4:
                f1Ex4_triang1();
                putchar('\n');
                f1Ex4_triang2();
                break;
            default:
                system("CLS");
                puts("$$$$$$$$ FALHA ARGUMENTOS SWITCH FICHA1 EM loadExercise() $$$$$$$$???");
                exit(1);
        }
    
    else if (ficha==2)
        switch(exercicio){
            case 0:
                return 1;
            case -1:
                return -1;
            case 1:
                printf("Insira 2 numeros (int,float): ");
                scanf("%d %f",&num1,&numfl1);
                printf("\nProduto de %d por %.3f = %.3f\n\n",num1,numfl1,multInt(num1,numfl1));
                break;
            case 2:
                printf("Insira 2 numeros (int,float): ");
                scanf("%d %f",&num1,&numfl1);
                printf("\nProduto de %d por %.3f = %.3f\n\n",num1,numfl1,f2Ex2(num1,numfl1));
                break;
            case 3:
                printf("Insira 2 numeros (int+,int+): ");
                scanf("%d %d",&num1,&num2);
                printf("\nMaximo divisor comum de %d e %d = %d\n\n",num1,num2,mdc(num1,num2));
                break;
            case 4:
                printf("Insira 2 numeros (int+,int+): ");
                scanf("%d %d",&num1,&num2);
                printf("\nMaximo divisor comum de %d e %d = %d\n\n",num1,num2,mdc2(num1,num2));
                break;
            case 5:
                printf("Insira 2 numeros (int+,int+): ");
                scanf("%d %d",&num1,&num2);
                printf("\nMaximo divisor comum de %d e %d = %d\n\n",num1,num2,mdc3(num1,num2));
                break;            
            case 6:
                f2Ex6b();
                break;
            default:
                system("CLS");
                puts("$$$$$$$$ FALHA ARGUMENTOS SWITCH FICHA2 EM loadExercise() $$$$$$$$???");
                exit(1);
        }
    
    else {
        system("CLS");
        puts("$$$$$$$$ FICHA INEXISTENTE EM loadExercise() $$$$$$$$???");
        exit(1);
    }

    return 0;
}