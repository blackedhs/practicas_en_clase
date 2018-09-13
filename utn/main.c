#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define   CANTIDAD_EMPLEADOS 5
#define CARGA_INVALIDA -1
int main()
{
    float numeroFloat;
    //char nombres[15][50];
    utn_getFloat(&numeroFloat,5,"numero","error Men",0,100);
    printf("%s",numeroFloat);
    return 0;
}
