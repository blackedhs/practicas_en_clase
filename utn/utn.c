
#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int getInt(int*resultado);
static int getFloat(float*pBuffer);
static int getString(char* bufferString);


int utn_getEntero(int*pEntero,int reintentos,char* msg,char*msgError,int min,int max){
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf("%s",msg);
        if(getInt(&auxiliarEdad) == 0)
        {
           if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEntero = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        else
        {
            printf("%s",msgError);
            __fpurge(stdin);
        }
    }
    return retorno;
}
int utn_getFloat(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max){
    int retorno = -1;
    float buffer;

    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0){
        do
        {
            reintentos--;
            printf("\n%s: ",msg);
            if(getFloat(&buffer) == 0 && buffer >= min && buffer<=max){
                    *pFloat= buffer;
                    retorno = 0;
                    break;
            }else{
                printf("\n %s ",msgError);
            }
        }while(reintentos > 0);
    }
    return retorno;
}
int utn_getChar(char*pResultado){
    char aux;
    int retorno=-1;
        if (scanf("%c",&aux)==1){
            *pResultado=aux;
            retorno=0;
    }
    return retorno;
}
int getInt(int*resultado){

    /**int aux;
    int retorno=-1;
        if (scanf("%d",&aux)==1){
            *resultado=aux;
            retorno=0;
    }
    return retorno;
    */
    char cadena[64];
    scanf("%s",cadena);
    int aux;
    if(!esNumero(cadena)){
        aux=atoi(cadena);
        *resultado=aux;
    }
    return 0;
}
int esNumero(char *pCadena){
    int retorno=0;
    int i=0;
    char aux;
    aux= pCadena[i];
    while(aux != 0)
    {
        if (aux <48 || aux >57)
        {
            retorno=-1;
            break;
        }
        i++;
        aux = pCadena[i];
    }
    return retorno;
}
int isFloat(char* pBuffer){
    int retorno=-1;
    int i=0;
    do{
        if(*pBuffer+i==','){
            *(pBuffer+i)='.';
            i++;
        }
        if(*pBuffer+i<48||*pBuffer+i>57){
        break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer)){
        retorno=0;
    }
    return retorno;
}
static int getString(char* pBuffer,int limite)
{
    char bufferString[4096];
    int retorno =-1
    if (pBuffer != NULL && limite >0){
        __fpurge(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if (bufferString[strlen(bufferString)-1]=='\n'){
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<= limite){
            strcpy(bufferString,pBuffer,limite);
            retorno=0;
        }
    }
    return retorno;
}
static int getFloat(float*pBuffer){
    char bufferString[200];
    int retorno =-1;
    if(getString(bufferString)==0 && isFloat(bufferString)==0){
        *pBuffer=atof(bufferString);
        retorno=0;
    }
    return retorno;
}
int utn_mostrarArray(int * pArray,int limite){
    int i;
    for (i=0;i<limite;i++){
        printf("\n%d",pArray[i]);
    }
    return 0;
}
int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo){
    int auxMax;
    int i;
    int retorno=-1;
    if(limite>0 && pArray!=NULL){
        retorno=0;
        for (i=0;i<limite;i++){
            if(i==0){
                auxMax=pArray[i];
            }else if(pArray[i]>auxMax){
                auxMax=*(pArray+i);
            }
        }
    }
    *maximo=auxMax;
    return retorno;
}
int utn_initArray(int * pArray,int limite,int valor){
    int i;
    int retorno=-1;
    if(limite>0 && pArray!=NULL){
        retorno=0;
        for (i=0;i<limite;i++){
            *(pArray+i)=valor;
        }
    }
    return retorno;
}

int utn_verificarNumeroEntero(int *pEntero,char* texto,char* textoError){
    int aux;
    printf("%s",texto);
    while(scanf("%d",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pEntero=aux;
    return 0;
}

int utn_verificarNumeroFloat(float *pFloat,char* texto,char* textoError){
    float aux;
    printf("%s",texto);
    while(scanf("%f",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pFloat=aux;
    return 0;
}

int utn_verificarNumeroChar(char *pChar,char* texto,char* textoError){
    char aux;
    printf("%s",texto);
    while(scanf("%c",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pChar=aux;
    return 0;
}
int utn_cargaNumeroAleatoriosEnArrays(int* pArray,int len,int min, int max){
    int i;
    srand(time(NULL));
    for (i=0;i<len;i++){
        pArray[i]= min+1 + rand() % (max+1-min);
    }
    return 0;
}

int utn_promedioArray(int*pArray,int limite,float *promedio,int valorOmision){
    int i;
    int cantidadValorOmision=0;
    int acumulador=0;
    int retorno=-1;

    for (i=0;i<limite;i++){
        if (pArray[i]==valorOmision){
            cantidadValorOmision++;
        }else{
            acumulador+=*(pArray+i);
            retorno=0;
        }
    }
    if(retorno==0){
        *promedio=acumulador/(limite-cantidadValorOmision);
    }
    return retorno;
}
int utn_ordenarArray(int *pArray,int limite,int flagMaxMin)
{
    int i=0;
    int aux;
    int retorno=-1;
    int flag=1;

    if(*pArray!=NULL&&limite>0){
        retorno=0;
        aux=pArray[i];
        while(flag==1){
            flag=0;
            for(i=0;i<(limite-1);i++){
                if( (flagMaxMin==1&& pArray[i]>pArray[i+1]) ||
                    (flagMaxMin==0&&pArray[i]<pArray[i+1]))
                {
                    flag=1;
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                }
            }
        }

    }
    return retorno;
}
