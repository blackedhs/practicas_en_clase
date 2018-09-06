
#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>

static int getInt(int*resultado);
static int getFloat(float*pResultado);


int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int min,int max){
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf("%s",msg);
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
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
int utn_getChar(char*pResultado){
    char aux;
    int retorno=-1;
        if (scanf("%c",&aux)==1){
            *pResultado=aux;
            retorno=0;
    }
    return retorno;
}
static int getInt(int*resultado){
    int aux;
    int retorno=-1;
        if (scanf("%d",&aux)==1){
            *resultado=aux;
            retorno=0;
    }
    return retorno;
}
static int getFloat(float*pResultado){
    float aux;
    int retorno=-1;
        if (scanf("%f",&aux)==1){
            *pResultado=aux;
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
