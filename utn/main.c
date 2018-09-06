#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define   CANTIDAD_EMPLEADOS 5
#define CARGA_INVALIDA -1
int main()
{
    int i;
    float promedio;
    int edades[CANTIDAD_EMPLEADOS];
    utn_initArray(edades,CANTIDAD_EMPLEADOS,CARGA_INVALIDA);

    for (i=0;i<CANTIDAD_EMPLEADOS;i++){
        utn_getEntero(&edades[i],3,"ingrese la edad:","La edad ingresada es erronea\n",0,199);
    }
    utn_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    utn_promedioArray(edades,CANTIDAD_EMPLEADOS,&promedio,CARGA_INVALIDA);
    printf("\n\nEl promedio de edades es : %.2f",promedio);

    return 0;
}
