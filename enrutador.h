#ifndef ENRUTADOR_H
#define ENRUTADOR_H


#include <math.h>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stdlib.h"

using namespace std;


class enrutador
{
private:
   map<char,unsigned >nodo;

public:
    enrutador();//char caracter  ,unsigned peso=0);
    void ingreso(char ,unsigned);
    void eliminacion(char);
    void cambio(char , unsigned peso=0);

};



#endif // ENRUTADOR_H
