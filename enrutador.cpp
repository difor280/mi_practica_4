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

string enrutador::leer()
{
    string caminos;
    for (auto i=nodo.begin();i != nodo.end();i++ )
    {
        caminos=caminos+i->first;
    }
    return caminos;
}

unsigned enrutador::sacar(char clave)
{
    return nodo[clave];
}

