#include "enrutador.h"

enrutador::enrutador()//char caracter  ,unsigned peso)
{
    //nodo[caracter]=peso;
}

void enrutador::ingreso(char caracter, unsigned int peso)
{
    nodo.insert(pair<char,unsigned>(caracter,peso));
}

void enrutador::eliminacion(char caracter )
{
    nodo.erase(caracter);
}

void enrutador::cambio(char caracter,unsigned peso)
{
    nodo[caracter]=peso;
}

