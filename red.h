#ifndef RED_H
#define RED_H

#include "enrutador.h"

class red
{
private:
    map<char ,enrutador>grafo;
    map<string,unsigned long> salidaC,Csalida;
    string nodosC;
    void conexion(char, char,unsigned);
    void ceros(string*);

public:
    red();
    bool Larchivo(string);
    void Lcrear();
    void borrar();

    void caminoO(char,char);

};

unsigned buscar(string cadena,char Caracter, bool *salir);
bool comparar(string cadena,string aporte);

#endif // RED_H
