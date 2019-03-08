#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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
// EXERCICIO 4 10/10
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
// EXERCICIO 6 10/10
//------------------------------------------------

int qDig (unsigned int n){
    int nTimes10=0;   
    
    if(n==0)
        return 1;
    
    while(n){
        nTimes10++;
        n=n/10;
    }

    return nTimes10;
}



//------------------------------------------------
// EXERCICIO 7 10/10
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
// EXERCICIO 8 10/10
//------------------------------------------------

char* myStrCpy (char* s1 , char* s2){
    int i;

    for(i=0 ; s2[i]!='\0' ; i++)
        s1[i]=s2[i];
    
    s1[i]='\0'; // adiciona '\0' no fim da string copiada
    
    return s1;
}



//------------------------------------------------
// EXERCICIO 9 10/10
//------------------------------------------------

int myStrcmp (char* s1 , char* s2){
    int i=0;

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
// EXERCICIO 10 10/10
//------------------------------------------------

char* myStrstr (char* s1 , char* s2){
    int indiceS2, indiceS1, indiceS1_2;
    
    if(s1[0]=='\0' && s2[0]=='\0') return s1;
    
    for (indiceS1=0 ; s1[indiceS1]!='\0' ; indiceS1++ )        
        for( indiceS1_2=indiceS1,indiceS2=0 ; s1[indiceS1_2]==s2[indiceS2] || s2[indiceS2]=='\0' ; indiceS1_2++,indiceS2++ )
            if(s2[indiceS2]=='\0')
                return s1+indiceS1;
    
    return NULL;
}



//------------------------------------------------
// EXERCICIO 11 10/10
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
// EXERCICIO 12 10/10
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
// EXERCICIO 14 10/10
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
// EXERCICIO 15 10/10
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
// EXERCICIO 17 10/10
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
// EXERCICIO 18 10/10
//------------------------------------------------

int maiorSufixo (char* s1, char* s2){

    int i_s1=1 , i_s2 , ch_cmp=0 , maxCount=0 , currentCount=0, i_maxSeq=0 , endS2=0;

    ch_cmp=strlen(s1)-1;
    endS2=strlen(s2)-1;
    
    while(ch_cmp!=-1){
        for ( 
                i_s1=ch_cmp , i_s2=endS2 ; 
                s1[i_s1]==s2[i_s2]; 
                i_s1--,i_s2--
            
            )
            {
              currentCount++;
              if(i_s1==0 || i_s2==0)
                break;
            }
            

            if(currentCount>maxCount){
                maxCount=currentCount;
                i_maxSeq=ch_cmp-maxCount+1;
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




//------------------------------------------------
// EXERCICIO 19
//------------------------------------------------

int sufPref ( char s1[] , char s2[]){
    
    // sem apetite :)
    
    return 0;
}





//------------------------------------------------
// EXERCICIO 20 10/10
//------------------------------------------------

int contaPal (char *s){
    int index=0,contador=0;

    while(s[index]!='\0'){
        
        if( isspace(s[index++])  )
            continue;
        
        for( index ; s[index]!=' ' && s[index]!='\0' ; index++);
            
        contador++;
    }

    return contador;
}




//------------------------------------------------
// EXERCICIO 21 10/10
//------------------------------------------------

int contaVogais (char *s){
    int index=0,contador=0;

    for(index=0 ; s[index]!='\0' ; index++){
        if 
            (
                s[index]=='A' || s[index]=='E' || s[index]=='I' || s[index]=='O' || s[index]=='U' ||
                s[index]=='a' || s[index]=='e' || s[index]=='i' || s[index]=='o' || s[index]=='u' 
            )
            contador++;
    }

    return contador;
}




//------------------------------------------------
// EXERCICIO 22 10/10
//------------------------------------------------

int contida (char *a, char *b){
    int indexA=0,indexB=0,iguais=0;

    if(a[0]=='\0')
        return 1;

    while ( indexA<=strlen(a)){
        for (indexB=0 ; indexB<=strlen(b) ; indexB++)
            if( a[indexA]==b[indexB] ){
                iguais++;
                break;
            }

        indexA++;
    }

    return iguais==(strlen(a)+1);
}




//------------------------------------------------
// EXERCICIO 23 10/10
//------------------------------------------------

int palindorome ( char *s ){
    int inicio=0,fim;
    fim=strlen(s)-1;

    //compara as sucessivas pontas da string
    while ( inicio!=fim && inicio<fim ){
        if(s[inicio]!=s[fim])
            return 0;
        inicio++;
        fim--;
    }

    return 1;
}




//------------------------------------------------
// EXERCICIO 24 10/10
//------------------------------------------------

int remRep (char *x){
    char temp[strlen(x)+1];
    int indeX=1,indexTemp=1;

    temp[0]=x[0];

    //preenche array temporario com a string final
    while(x[indeX]!='\0'){
        if( x[indeX]==temp[indexTemp-1] ){
            indeX++;
            continue;
        }
            
        temp[indexTemp]=x[indeX];
        indeX++;
        indexTemp++;
    }
    temp[indexTemp]='\0';
    
    //mete resultado final em t
    strcpy(x,temp);

    return strlen(x);
}




//------------------------------------------------
// EXERCICIO 25 10/10
//------------------------------------------------

int limpaEspacos (char *t){
    int indexT=0,indexTemp=0;
    char temp[strlen(t)+1];

    //preenche array temporario com a string final
    while( t[indexT]!='\0' ){
        
        if(temp[indexTemp-1]==' ' && t[indexT]==' '){
            indexT++;
            continue;
        }

        temp[indexTemp]=t[indexT];
        indexT++;
        indexTemp++;
    }
    temp[indexTemp]='\0';

    //mete resultado final em t
    strcpy(t,temp);

    return strlen(t);
}




//------------------------------------------------
// EXERCICIO 26 10/10
//------------------------------------------------

void insere (int *v, int N, int x){
    int indexInsere=0,index=0;

    //encontra indice a inserir
    for(indexInsere=0 ; v[indexInsere]<x && indexInsere<N ; indexInsere++);

    //fim do vector
    if(indexInsere==N)
        v[indexInsere]=x;
    //dentro do vector
    else {
        //move todos os elementos do fim ate indice insercao 1 posicao a frente
        for(index=N-1 ; index!=indexInsere-1 ; index--)
            v[index+1]=v[index];
        
        v[indexInsere]=x;// insere valor
    }
}




//------------------------------------------------
// EXERCICIO 27 10/10
//------------------------------------------------

void myMerge (int r[],int a[], int b[], int na, int nb){
    int indexA=0,indexB=0,indexR=0;

    while(indexR<na+nb){
        if(indexA==na)
            r[indexR] = b[indexB++];
        else if(indexB==nb)
            r[indexR] = a[indexA++];        
        else 
            r[indexR] = ( a[indexA]<b[indexB] ) ? a[indexA++] : b[indexB++];

        indexR++;
    }
}




//------------------------------------------------
// EXERCICIO 28 10/10
//------------------------------------------------

int crescente (int *a , int i, int j){
    while( i!=j ){
        if( a[i]>a[i+1] )
            return 0;
        i++;
    }

    return 1;
}



//------------------------------------------------
// EXERCICIO 29 10/10
//------------------------------------------------

int retiraNeg (int *v, int N){
    int temp[N];
    int index=0,indexInsere=0,contador=0;

    for(index=0 ; index<N ; index++)
        temp[index]=v[index];
    
    for(index=0 ; index<N ; index++){
        v[index]=0; // reset array v
        if(temp[index]>=0){
            v[indexInsere]=temp[index];
            indexInsere++;
            contador++;
        }
    }
    
    return contador; 
}




//------------------------------------------------
// EXERCICIO 30 10/10
//------------------------------------------------

int menosFreq (int *v, int sizeV){
    int index=0,indexCompara,contador=0,minCounter=sizeV+1,min;

    min=v[0];

    while(index<sizeV){
        for(indexCompara=index ; indexCompara<sizeV && v[index]==v[indexCompara] ; indexCompara++ )
            contador++;
        if(contador<minCounter){
            min=v[index];
            minCounter=contador;
        }
        index+=contador; // jump ocorrencias iguais do num
        contador=0;
    }
    return min;
}



//------------------------------------------------
// EXERCICIO 31 10/10
//------------------------------------------------


int maisFreq (int *v, int sizeV){
    int index=0,indexCompara,contador=0,maxCounter=0,max;

    while(index<sizeV){
        for(indexCompara=index ; indexCompara<sizeV && v[index]==v[indexCompara] ; indexCompara++ )
            contador++;

        if(contador>maxCounter){
            max=v[index];
            maxCounter=contador;
        }
        index+=contador; // jump ocorrencias iguais do num
        contador=0;
    }
    return max;
}



//------------------------------------------------
// EXERCICIO 32 10/10
//------------------------------------------------

int maxCresc (int v[],int sizeV){
    int index=0,index2,maxCounter=0,contador=1;
    
    while(index<sizeV){
        for(index2=index+1 ; v[index]<=v[index2] && index2<sizeV ; index2++,index++)
            contador++;
        
        if(contador>maxCounter)
            maxCounter=contador;
        
        index++;
        contador=1;
    }
    return maxCounter;
}



//------------------------------------------------
// EXERCICIO 33 10/10
//------------------------------------------------

int elimRep (int v[], int n){
    int indexCopia,indexV,indexEscrita=0,newSizeV=0;
    int copia[n];
    
    // copia de v
    for(indexV=0 ; indexV<n ; indexV++)
        copia[indexV]=v[indexV];

    // indice de escrita representa onde colocar o inteiro em v, se este nao existir
    
    //percorre copia
    for(indexCopia=0 ; indexCopia<n ; indexCopia++ ){
        //verifica se elemento de copia ja existe ate ao indice de escrita de v
        for(indexV=0 ; indexV<=indexEscrita ; indexV++)
            if(copia[indexCopia]==v[indexV]){
               indexV++; // necessario incrementar por causa da decremento seguinte
               break;
            }
       
        indexV--; // necessario decrementar por causa do <= ciclo for
        if(indexV==indexEscrita){ // se verdade, elemento ainda nao existe
            v[indexEscrita]=copia[indexCopia];
            indexEscrita++;
            newSizeV++;
        }
        
    }
    
    return newSizeV;
}


//------------------------------------------------
// EXERCICIO 34 10/10
//------------------------------------------------

int elimRepOrd(int v[], int sizeV){
    int newSize=1,index=1,indexInsere=1;
    
    if(!sizeV) return 0;

    while(1){
        for(index; v[index]==v[index-1] && index<sizeV ; index++);
    
        if(index==sizeV) break;
        
        v[indexInsere]=v[index];
        index++;
        indexInsere++;
        newSize++;
    }
    
    return newSize;
}




//------------------------------------------------
// EXERCICIO 35 10/10 
//------------------------------------------------

int comunsOrd (int a[],int sizeA, int b[], int sizeB){
    int contador=0,indexA=0,indexB=0;
    
    if(!sizeA || !sizeB) return 0;
    
    while(indexA<sizeA && indexB<sizeB){
        
        if(a[indexA]==b[indexB]){
            contador++;
            indexA++;
            indexB++;
        }
        else if(a[indexA]>b[indexB])
            for(indexB+=1 ; b[indexB]==b[indexB-1] && indexB<sizeB; indexB++);
        else
            for(indexA+=1 ; a[indexA]==a[indexA-1] && indexA<sizeA; indexA++);
    }

    return contador;
} 




//------------------------------------------------
// EXERCICIO 36 
//------------------------------------------------

int comuns (int a[], int sizeA, int b[], int sizeB){
    int indexA=0,indexB=0,contador=0;
    
    if(!sizeA || !sizeB) return 0;

    //procura do vector a em b
    for(indexA=0 ; indexA<sizeA ; indexA++)
        for(indexB=0 ; indexB<sizeB ; indexB++)
            if(a[indexA]==b[indexB])
                contador++;

    return contador;
}



//------------------------------------------------
// EXERCICIO 37 10/10 
//------------------------------------------------

int minInd (int v[], int sizeV){
    int index=1,minIndex,minNum;
    
    if(!sizeA || !sizeB) exit(1);
    
    minNum=v[0];
    minIndex=0;

    for(index=1 ; index<sizeV ; index++ )
        if(v[index]<minNum){
            minNum=v[index];
            minIndex=index;
        }

    return minIndex;
}



//------------------------------------------------
// EXERCICIO 38 10/10 
//------------------------------------------------

void somasAc (int v[], int Ac[], int sizeV){
    int indexAc=0,percorreV=0,soma=0;
   
    if(!sizeV) return;

    while(indexAc<sizeV){
        for(percorreV=0 ; percorreV<=indexAc ; percorreV++)
            soma+=v[percorreV];
        
        Ac[indexAc]=soma;
        soma=0;
        indexAc++;
    }
}




//------------------------------------------------
// EXERCICIO 39 10/10 
//------------------------------------------------

int triSup (int dim, float m[dim][dim]){
    int linha=0,coluna=0;

    for(linha=0 ; linha<dim ; linha++)
        for(coluna=0 ; coluna<dim && coluna<linha ; coluna++){
            if(m[linha][coluna]!=(0,0) && coluna<linha)
                return 0; // 0 -> FALSE
        }
    
    return 1;
}




//------------------------------------------------
// EXERCICIO 40 10/10 
//------------------------------------------------

void transposta (int sizeM , float m[sizeM][sizeM]){
    
    int linha=0,coluna=0;
    float temp;

    for(linha=0 ; linha<dim ; linha++)
        for(coluna=0 ; coluna<dim && coluna<linha ; coluna++){
            temp=m[linha][coluna];
            m[linha][coluna]=m[coluna][linha];
            m[coluna][linha]=temp;
        }
}





//------------------------------------------------
// EXERCICIO 41 10/10 
//------------------------------------------------

void addTo (int maxL, int maxC, int a[maxL][maxC], int b[maxL][maxC]){
    int linha=0,coluna=0;
    
    for(linha ; linha<maxL ; linha++)
        for(coluna=0 ; coluna<maxC ; coluna++)
            a[linha][coluna]+=b[linha][coluna];
}




//------------------------------------------------
// EXERCICIO 42 10/10 
//------------------------------------------------

// v1 e v2 sao arrays de 0(zero) e 1 correspondete aos indices
int unionSet (int dim, int v1[dim], int v2[dim], int r[dim]){
    int index=0,contador=0;
    
    if(!dim) return 0;

    while(index<dim){
        if( v1[index] || v2[index] ){
            r[index]=1;
            contador++;
        }
        else
            r[index]=0;
        index++;
    }
    return contador;
}




//------------------------------------------------
// EXERCICIO 43 10/10 
//------------------------------------------------

int intersectSet (int dim, int v1[dim], int v2[dim], int r[dim]){
    int index=0,contador=0;
    
    if(!dim) return 0;

    while(index<dim){
        if( v1[index] && v2[index] ){
            r[index]=1;
            contador++;
        }
        else
            r[index]=0;
        index++;
    }
    return contador;
}




//------------------------------------------------
// EXERCICIO 43 10/10 
//------------------------------------------------

int intersectMSet (int dim, int v1[dim], int v2[dim], int r[dim]){
    return 1;
} 


