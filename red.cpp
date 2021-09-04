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

    char cla;
    for(auto i= grafo.begin();i!=grafo.end();i++)
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
        {       unsigned memoria=datos.length()-4;
                char nodo1,nodo2,numero[memoria];
                unsigned peso=datos.length();
                for(unsigned i =4,e=0 ;i<peso;i++,e++)
                {
                      numero[e]=datos[i];
                }
                nodo1=datos[0];
                nodo2= datos[2];
                peso=atoi(numero);
                if(memoria==1) peso=peso/10;
                conexion(nodo1,nodo2,peso);

        }
    }
    else
    {
        ar=false;
    }
    //ceros(&nodosC);
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

void red::borrar()
{   bool salida= 1;
    char eliminar;
    while(salida)
    {
        cout<<"ingresa el nombre del enrutador a borrar"<<endl;

        cin>>eliminar;
        grafo.erase(eliminar);
        for(auto i= grafo.begin(); i != grafo.end();i++)
        {

            if(i->first != eliminar)
            {
                enrutador a=i->second;
                a.eliminacion(eliminar);
                grafo[i->first]=a;
            }



        }
        cout<<"0.parar\n"
              "1.eliminar nodo\n";
        cin>>salida;

    }

}

void red::caminoO(char salir, char llegar)
{
    bool a=1,esta,comprobar;
    enrutador caminos;//,caminos1[llegar];
    unsigned tam=0;
    unsigned long contenido=0,peso=0;
    string rutas="",enruta1,llaves,conte;//,enruta2,rutas2="";
    char sumar;
    enruta1=salir;
    //enruta2=llegar;
    salidaC[enruta1]=peso;
    //Cllegada[enruta2]=peso;

    while (a)
    {   Csalida=salidaC;
        auto i =Csalida.begin();
        tam=i->second;
        for(;i!=Csalida.end();i++)
        {
            if(tam>=i->second)
            {
                rutas=i->first;
                tam=i->second;
            }
        }

          //rutas=caminos pasar

            tam=rutas.length()-1;
            caminos=grafo[rutas[tam]];
            llaves=caminos.leer();


            if(!comparar(rutas,llaves))
            {
                for(unsigned e=llaves.length()-1;e>=0;e--)
                {
                    sumar=llaves[e];
                    caminos.sacar(sumar);
                    contenido=peso;                    

                    tam=buscar(rutas,sumar,&esta);
                    buscar(rutas,llegar,&comprobar);

                     if(!esta )
                    {
                        contenido=contenido+caminos.sacar(sumar);
                        conte=rutas+sumar;
                        salidaC[conte]=contenido;
                        cout<<conte<<endl;
                        cout<<contenido<<endl;

                    }
                    if(e==0) break;

                 }
            }
            else if(rutas[tam]==llegar)
            {   comprobar=true;
                for(unsigned e=llaves.length()-1;e>=0;e--)
                {
                    contenido=peso;
                    sumar=llaves[e];
                    tam=buscar(rutas,sumar,&esta);
                    if(!(rutas[tam]==llegar))
                    {
                        comprobar=false;
                        break;
                    }
                }
            }

            salidaC.erase(rutas);


        if(comprobar)
        {
            break;
        }
    }

}

unsigned buscar(string cadena,char Caracter, bool *salir)
{
    unsigned encontrar=0;
    for(unsigned i=cadena.length()-1;i>=0;i--)
    {
        if(cadena[i]==Caracter)
        {
            encontrar=i;
            *salir=1;
            return encontrar;
        }
         if (i==0) break;
    }
    *salir=0;
    return encontrar;
}

// si salida es negativa sale
bool comparar(string cadena,string aporte)
{
    int tam=aporte.length() ;
    bool salida=1;
   for(int i =0; i < tam ;i++)
   {
        buscar(cadena,aporte[i],&salida);
        if(!salida)
        {
            break;
        }
   }
    return salida;
}

