#include "red.h"

void red::conexion(char nodo1,char nodo2, unsigned peso)
{
    enrutador grafo1=grafo[nodo1],grafo2=grafo[nodo2];
    grafo1.cambio(nodo2,peso);
    grafo2.cambio(nodo1,peso);
    grafo[nodo1]=grafo1;
    grafo[nodo2]=grafo2;
}

void red::ceros(string *clave)
{
    enrutador nodo;
    unsigned e=0;
    char cla;
    for(auto i= grafo.begin();i!=grafo.end();i++,e++)
    {
        cla=i->first;
        *clave=*clave+cla;
        nodo=i->second;
        nodo.cambio(cla);
        grafo[cla]=nodo;
    }
}

red::red()
{

}

bool red::Larchivo(string  nombre_nodos)
{
    bool ar=true;
    fstream text;
    text.open(nombre_nodos,fstream::in);
    string datos;
    if(text.is_open())
    {
        nombre_nodos="";
        while(getline(text,datos))
        {
                char nodo1,nodo2,numero[datos.length()-4];
                unsigned peso=datos.length();
                for(unsigned i =4,e=0 ;i<peso;i++,e++)
                {
                      numero[e]=datos[i];
                }
                nodo1=datos[0];
                nodo2= datos[2];
                peso=atoi(numero);
                conexion(nodo1,nodo2,peso);

        }
    }
    else
    {
        ar=false;
    }
    text.close();
    return ar;
}

void red::Lcrear()
{   bool iter=1;
    while (iter)
    {   char numero[4];
        char nodo1,nodo2;
        unsigned peso;
        cout<<"ingresa los caracteres que identifican los enrutadores que estan enlazados\n"
              "(si ingresas mas de los dos caracteres permitidos no se tengran en cuenta)\n"
              "ej: si los nodos son A y B entonces se escribe AB"<<endl;
        cin>>numero;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        nodo1=numero[0];
        nodo2=numero[1];
        iter=false;
        while(!iter)
        {
            cout<<"ingresa el costo de la union\n";
            cin>>numero;
            if(numero[0]>48 and numero[0]<=57)
            {
                iter=1;
            }
            else
            {
                cout<<"el dato no es un numero ,";
            }
        }
        peso=atoi(numero);
        conexion(nodo1,nodo2,peso);
        peso=1;
        while (peso)
        {

            cout<<"1.ingresar\n"
                  "0.parar\n";
            cin>>numero;
            if(numero[0]=='1' or numero[0]=='0')
            {
                    peso=0;
                    iter=int(numero[0]-48);
            }
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }
        ceros(&nodosC);

    }

}

/*void red::mejorR(char desde,char hasta)
{
    llegada[desde]=



}*/

void red::sacar(char nodo, char inf)
{
    enrutador a = grafo[nodo];



}



