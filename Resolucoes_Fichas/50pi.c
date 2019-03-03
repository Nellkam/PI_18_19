#include <stdio.h>
#include <stdlib.h>




//------------------------------------------------
// EXERCICIO 1
//------------------------------------------------

void ex1(){
    int num=1,maior;
    
    printf("Insira sequencia de numeros inteiros ( 0 -> terminar ): ");
    scanf("%d",&maior);
    
    if(getchar()==(int)'\n')
        num=0;
    
    while(num){
        scanf("%d",&num);
        maior= (num>maior) ? num : maior;
    }
    printf("\n-> Maior numero inteiro inserido: %d",maior);
}



//------------------------------------------------
// EXERCICIO 2
//------------------------------------------------

void ex2(){
    int num=1,soma=0;
    float numLidos=0.0;

    printf("Insira sequencia de numeros inteiros: ");
    while(num){
        scanf("%d",&num);
        soma+=num,
        numLidos++;
    }

    printf("%f",soma/numLidos);
}



//------------------------------------------------
// EXERCICIO 3
//------------------------------------------------

void ex3(){
    int num=1,maior1=0,maior2=0,temp;

    printf("Insira sequencia de numeros inteiros: ");
    
    scanf("%d",&maior1);
    if(!maior1) 
        return;
    
    scanf("%d",&maior2);
    if(!maior2){
        printf("Maior: %d / 2nd Maior: not defined ",maior1);
        return;
    }
    
    if(maior2>maior1){
        temp=maior1;
        maior1=maior2;
        maior2=temp;
    }

    while(num){
        scanf("%d",&num);
        
        if(!num) 
            break;

        temp=maior1;
        maior1 = (num>maior1) ? num : maior1;

        if(maior1==num)        
            maior2= (temp>maior2) ? temp : maior2;
        else
            maior2= (num>maior2) ? num : maior2;
    } 
    printf("Maior: %d / 2nd Maior: %d ",maior1,maior2);
}



//------------------------------------------------
// EXERCICIO 4
//------------------------------------------------

int bitsUm (unsigned int n){
    int howMany1=0;

    while(n){
        howMany1+=n%2;
        n=n/2;
    }
    return howMany1;
}



//------------------------------------------------
// EXERCICIO 5
//------------------------------------------------

int trailingZ (unsigned int n){
    
    // enunciado merdoso nao faz sentido......wtf

    return 0;
}



//------------------------------------------------
// EXERCICIO 6
//------------------------------------------------

int qDig (unsigned int n){
    int nTimes10=0;
    
    while(n>1){
        n=n/10;
        nTimes10++;
    }

    return nTimes10;
}



//------------------------------------------------
// EXERCICIO 7
//------------------------------------------------

char* myStrcat (char* s1 , char* s2){
    int i=0,j;

    while(s1[i]!='\0')
        i++;
    
    for( i,j=0 ; s2[j]!='\0' ; i++,j++)
        s1[i]=s2[j];
    
    s1[i]='\0'; // adiciona '\0' no fim da string concatenada

    return s1;    
}



//------------------------------------------------
// EXERCICIO 8
//------------------------------------------------

char* myStrCpy (char* s1 , char* s2){
    int i;

    for(i=0 ; s2[i]!='\0' ; i++)
        s1[i]=s2[i];
    
    s1[i]='\0'; // adiciona '\0' no fim da string copiada
    
    return s1;
}



//------------------------------------------------
// EXERCICIO 9
//------------------------------------------------

int myStrcmp (char* s1 , char* s2){
    int i;

    while(1){            

        if( s1[i]=='\0' && s2[i]=='\0' )
            return 0;        
        else if( s1[i] > s2[i] )
            return 1;
        else if ( s1[i] < s2[i] )
            return -1;
        else
            i++;        
    }
}



//------------------------------------------------
// EXERCICIO 10
//------------------------------------------------

char* myStrstr (char* s1 , char* s2){
    int indiceS2, indiceS1, indiceS1_2;

    for (indiceS1=0 ; s1[indiceS1]!='\0' ; indiceS1++ ){
        
        if( s1[indiceS1]==s2[0] ) // quando encontrar o char inicial de s2 em s1 -> verifica proximos indices
            for ( indiceS2=1 , indiceS1_2=indiceS1+1 ; ; indiceS2++,indiceS1_2++){               
                if( s2[indiceS2]=='\0' ) // caso seja fim de s2 -> s1 contem s2
                    return s1+indiceS2; // apontador para primeiro indice que s1 contem s2
                if( s1[indiceS1_2]=='\0' ) // caso se detecte o fim de s1 -> nao contem s2
                    return NULL;
                if( s1[indiceS1_2]!=s2[indiceS2] ) // caso sejam diferentes termina este ciclo
                    break; // retoma ciclo inicial                                
            }    
    }

    return NULL;
}



//------------------------------------------------
// EXERCICIO 11
//------------------------------------------------

void myStrrev (char* s){
    int endS=0,i,temp;

    while( s[endS]!='\0' )
        endS++;
    
    endS--;//elemento anterior a '\0'
    for(i=0, endS ; (i!=endS && i!=endS+1) ; i++,endS--){
        temp=s[i];
        s[i]=s[endS];
        s[endS]=temp;
    }
    
}



//------------------------------------------------
// EXERCICIO 12
//------------------------------------------------

void myStrnoV (char* s){
    int i,j;
    
    for(i=0 ; s[i]!='\0' ; i++){        
        if  ( 
                s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || 
                s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'
            )
            {
                for(j=i ; s[j]!='\0' ; j++)
                    s[j]=s[j+1]; // copia resto string em i
                i--;            // reve mesmo i
            }                  
    }
}



//------------------------------------------------
// EXERCICIO 13
//------------------------------------------------

void truncW (char* t, int n){
    int i=0,j,counter,space_end;

    while( t[i]!='\0' ){
        
        // se for inicio de palavra
        if( (t[i]!=' ' && i==0) || (t[i]!=' ' && t[i-1]==' ') ){
            
            //calcula i para truncar
            for(counter=0 ; t[i]!=' ' && counter<=n ; i++,counter++ );

            //calcula indice termino palavra (espaco ou '\0')
            for(space_end=i ; t[space_end]!=' ' && t[space_end]!='\0' ; space_end++);            

            // se termino palavra é fim de string -> trunca
            if ( t[space_end]=='\0' ){                
                t[i]='\0';
                return;        
            }                

            // caso contrario trunca em i copiando espaço e resto string 
            else {
                for(j=i ; t[space_end]!='\0' ; j++,space_end++)
                    t[j]=t[space_end]; // trunca
                t[space_end]='\0'; // marcar novo fim de string
            }          
        }       
        
        i++;

    }

}




//------------------------------------------------
// EXERCICIO 14
//------------------------------------------------

char charMaisfreq (char* s){
    
    // i_maxCh -> indice char com mais ocorrencias
    // ch_cmp -> indice atual em s
    // i -> indice de comparacao
    
    int maxCount=0,currentCount=0;
    int i_maxCh=0,ch_cmp=0,i=0;

    if(s[0]=='\0')
        return 0;  

    while( s[ch_cmp]!='\0' ){

        for( i=0 ; s[i]!='\0' ; i++ )
            if( s[i]==s[ch_cmp] )
                currentCount++;

        if( currentCount>maxCount ){
            maxCount=currentCount;
            i_maxCh=ch_cmp;            
        }

        ch_cmp+=currentCount+1; // jump ocorrencias
        currentCount=0;
    }

    printf("Char mais Frequente %c com %d ocorrencias\n\n",s[i_maxCh],maxCount);
    
    return s[i_maxCh];

}



//------------------------------------------------
// EXERCICIO 15
//------------------------------------------------

int iguaisConsecutivos (char* s){
    
    // i_maxSeq -> indice sequencia maxima
    // ch_cmp -> indice actual em s
    // i -> indice de comparacao
    
    int i,i_maxSeq=0,ch_cmp=0,maxCount=0,currentCount=0;

    while( s[ch_cmp]!='\0' ){

        for ( i=ch_cmp ; s[i]==s[ch_cmp] && s[i]!='\0' ; i++ )
            currentCount++;
        
        if( currentCount>maxCount ){
            maxCount=currentCount;
            i_maxSeq=ch_cmp;
        }

        currentCount=0;
        ch_cmp++;
    }

    printf("Maior sequencia de chars consecutivos: %c com %d ocorrencias\n\n",s[i_maxSeq],maxCount);

    return maxCount;
}



//------------------------------------------------
// EXERCICIO 16
//------------------------------------------------

int difConsecutivos (char* s){
    
    // i_maxSeq -> indice sequencia maxima
    // ch_cmp -> indice actual em s
    // i -> indice de comparacao
    
    int i,i_maxSeq=0,ch_cmp=0,maxCount=0,currentCount=1;

    while( s[ch_cmp]!='\0' ){
        
        for ( i=ch_cmp+1 ; s[i]!=s[i-1] && s[i]!='\0' && s[i]!='\n' ; i++)
            currentCount++;
        
        if(currentCount>maxCount){
            maxCount=currentCount;
            i_maxSeq=ch_cmp;
        }

        currentCount=1;
        ch_cmp++;
    }

    printf("Maior sequencia de chars diferentes e de %d chars: \"",maxCount);
    for(i=maxCount ; i>0 ; i--,i_maxSeq++)
        printf("%c",s[i_maxSeq]);
    printf("\"\n\n");
    
    return maxCount;
}



//------------------------------------------------
// EXERCICIO 17
//------------------------------------------------

int maiorPrefixo (char* s1, char* s2){
    
    // i_maxSeq -> indice sequencia maxima
    // ch_cmp -> indice actual em s1
    // i_s1 -> indice de comparacao s1
    // i_s2 -> indice de comparacao s2
    
    int i_s1 , i_s2 , ch_cmp=0 , maxCount=0 , currentCount=0, i_maxSeq=0;

    while ( s1[ch_cmp]!='\0' ){

        for (   
                i_s1=ch_cmp , i_s2=0 ; 
                s1[i_s1]==s2[i_s2] && s1[i_s1]!='\n' && s2[i_s2]!='\n' 
                                   && s1[i_s1]!='\0' && s2[i_s2]!='\0'; 
                i_s1++,i_s2++ 
            )
            currentCount++;
        
        if(currentCount>maxCount){
            maxCount=currentCount;
            i_maxSeq=ch_cmp;
        }

        currentCount=0;
        ch_cmp++;
    }

    printf("Maior Prefixo e de %d chars: \"",maxCount);
    for(i_s1=maxCount ; i_s1>0 ; i_s1--,i_maxSeq++)
        printf("%c",s1[i_maxSeq]);
    printf("\"\n\n");

    return maxCount;
}



//------------------------------------------------
// EXERCICIO 18
//------------------------------------------------

int maiorSufixo (char* s1, char* s2){

    int i_s1=1 , i_s2 , ch_cmp=0 , maxCount=0 , currentCount=0, i_maxSeq=0 , endS2=0;

    while( s1[ch_cmp]!='\0' && s2[endS2]!='\0'  ){
        ch_cmp++;
        endS2++;
    }

    while(i_s1){
        for ( 
                i_s1=ch_cmp , i_s2=endS2 ; 
                s1[i_s1]==s2[i_s2] && i_s1!=-1 && i_s2!=-1 ; 
                i_s1--,i_s2--
            
            )
            currentCount++;

            if(currentCount>maxCount){
                maxCount=currentCount;
                i_maxSeq=ch_cmp-maxCount;
            }

            ch_cmp--;
            currentCount=0;
    }

    printf ("Maior sufixo e de %d chars: \"",maxCount);
    for(i_s1=maxCount ; i_s1>0 ; i_s1--,i_maxSeq++)
        printf("%c",s1[i_maxSeq]);
    printf("\"\n\n");

    return maxCount;
}
