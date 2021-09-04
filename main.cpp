  #include "red.h"

int main()
{
    red graf;
    char menu;
    string nombre;
    bool salir=1;
    while (salir)
    {

        cout<<"\nMENU\n"<<endl;
        cout<<"de que manera vas a ingresar tu matriz\n"
              "1.archivo\n"
              "2.manual\n";
        cin>>menu;
        switch (menu)
        {
        case '1':
            salir=0;
            cout<<"ingresa el nombre del archivo";
            cin>>nombre;
            graf.Larchivo(nombre);
            break;
        case '2':
            salir=0;
            graf.Lcrear();
            break;
        }
    }
    salir=1;
    while (salir)
    {
        cout<<"\ndesea borrar nodos ?\n"
              "1.si\n"
              "2.no\n";
        cin>>menu;
        switch (menu)
        {
        case '1':
            salir=0;
            graf.borrar();
            break;
        case '2':
            salir=0;
            break;
        }
    }

    graf.caminoO('A','D');
    return 0;
}
