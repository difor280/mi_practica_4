#ifndef RED_H
#define RED_H

#include "enrutador.h"

class red
{
private:
    map<char ,enrutador>grafo;
    map<string,unsigned long> llegada,salida;
    string nodosC;
    void conexion(char, char,unsigned);
    void ceros(string*);

public:
    red();
    bool Larchivo(string);
    void Lcrear();
    void mejorR(char,char);
    void sacar (char, char);
};

#endif // RED_H
