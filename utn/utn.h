#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/**
    utn_getentero : Pide un numero entero al usuario
    @param pEdad : puntero a edad
    @param reintentos: cantidad de intentos
    @param msg: puntero a un mensaje
    @param msgError: puntero a un msj error
    @return 0 is ok, -1 error
*/
int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int max,int min);

#endif // UTN_H_INCLUDED
