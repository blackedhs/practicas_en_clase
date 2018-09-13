#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define   CANTIDAD_EMPLEADOS 5
#define CARGA_INVALIDA -1
int main()
{
    int numeroInt;
    //char nombres[15][50];
    utn_getEntero(&numeroInt,5,"numero","error Men",0,100);
    printf("%d",numeroInt);
    return 0;
}
