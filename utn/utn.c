
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
        printf(msg);
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
                printf(msgError);
            }
        }
        else
        {
            printf(msgError);
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
int mostrarArray(int * pArray,int limite){
    int i;
    for (i=0;i<limite;i++){
        printf("\n%d",pArray[i]);
    }
    return 0;
}
int calcularNumeroMaximo(int *pArray,int limite,int *maximo){
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
int initArray(int * pArray,int limite,int valor){
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
