#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define   CANTIDAD_EMPLEADOS 5
#define CARGA_INVALIDA -1
typedef struct{
    char nombre[15];
    int edad;
    float altura;
    char dni;
}Persona;
int printPersona(Persona* pBuffer);
int altaPersona(Persona* persona);
int main()
{
    Persona p;

    altaPersona(&p);
    printPersona(&p);
    return 0;
}
int printPersona(Persona *pBuffer){
    printf("\tNombre\taltura\tedad:\n\n");
    printf("\t%s\t%.2f\t%d",pBuffer->nombre,pBuffer->altura,pBuffer->edad);
    return 0;
}
int altaPersona(Persona* persona){
    printf("\nIngrese el nombre: : ");
    fgets(persona->nombre,4,stdin);
    utn_getEntero(&persona->edad,3,"Ingrese la edad: ","Error intente nuevamente : ",0,100);
    utn_getFloat(&persona->altura,3,"Ingrese su altura: ","Error amiguito: ",0.0,3.00);
    return 0;
}
