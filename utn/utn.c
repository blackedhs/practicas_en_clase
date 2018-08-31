#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>

static int getInt(int*resultado);

int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int max,int min){
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
static int getInt(int*resultado){
    int aux;
    int retorno=-1;
        if (scanf("%d",&aux)==1){
            *resultado=aux;
            retorno=0;
    }
    return retorno;
}
