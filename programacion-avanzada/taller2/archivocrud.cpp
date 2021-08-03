/**********************************************************************/
/*******              COMPLETAR EL SIGUIENTE PROGRAMA           *******/
/**********************************************************************/

/** 1. INCLUIR EL CODIGO NECESARIO PARA MODIFICAR REGISTROS **/
/** 2. INCLUIR EL CODIGO NECESARIO PARA ELIMINAR REGISTROS **/
    /** COMO LO PODEMOS HACER?? OPCIONES: */
    /** A. CARGAR TODO EL ARCHIVO EN MEMORIA, SE ELIMINA LO QUE SE SE REQUIERE Y LO VOLVEMOS A GRABAR (ARCHIVOS PEQUENOS) **/
    /** B. SE UTILIZA UN ARCHIVO TEMPORAL, PARA COPIAR LOS REGISTROS ANTIGUOS Y NUEVOS. SE ELIMINA EL ARCHIVO Y SE REEMPLAZA POR EL TEMPORAL  **/
    /** C. SE PODRÍA ABRIR EL ARCHIVO DE LETURA Y ESCRITURA Y DESPLZARSE POR EL ARCHIVO Y UTILIZAR EL TRUNCADO DE ARCHIVO.   **/
/** UTILICE FUNCIONES PARA REEMPLAZAR CODIGO QUE SE REPITE. EJEMPLO, LA IMPRESION DE REGISTRO  **/


#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    int identificador,opcion, buscarId;
    char palabra1[20],palabra2[20], palabra1sus[20],palabra2sus[20];
    char nuevaPalabra1[20],nuevaPalabra2[20];
    string nombreArchivo = "Operacion.txt";
    ofstream Guardar;
    ifstream Leer;
    ofstream Temp; //archivo logico temporal


    while(true)
    {
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<"1 GUARDAR"<<endl;
        cout<<"2 LEER"<<endl;
        cout<<"3 BUSCAR"<<endl;
        cout<<"4 MODIFICAR"<<endl;
        cout<<"5 ELIMINAR"<<endl;
        cout<<"6 SALIR"<<endl;
        cout<<"%%%%%%%%%%%%%%%%%"<<endl;
        cout<<endl;
        cout<<"Elija una opcion:"<<endl;
        cin>>opcion;

        system("clear");

        switch(opcion)
        {
            case 1:
                {
                    Guardar.open(nombreArchivo,ios::app);
                    cout<<"Ingrese Palabra1: ";
                    cin>>palabra1;
                    cout<<"Ingrese Palabra2: ";
                    cin>>palabra2;
                    cout<<"Ingrese un identificador: ";
                    cin>>identificador;
                    Guardar<<palabra1<<" "<<palabra2<<" "<<identificador<<endl;
                    Guardar.close();
                    break;
                }
            case 2:
                {
                    Leer.open(nombreArchivo);
                    Leer>>palabra1>>palabra2;
                    Leer>>identificador;
                    while(!Leer.eof())
                    {
                        cout<<"----------------------------"<<endl;
                        cout<<"palabra1:     "<<palabra1 <<endl;
                        cout<<"palabra2:     "<<palabra2 <<endl;
                        cout<<"identificador:"<<identificador <<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<endl;
                        Leer>>palabra1>>palabra2>>identificador;
                    }
                    Leer.close();
                    break;
                }
            case 3:
                {
                    Leer.open(nombreArchivo);
                    Leer>>palabra1>>palabra2>>identificador;
                    bool encontrado=false;
                    cout<<"Ingrese su identificador a buscar"<<endl;
                    cin>>buscarId;
                    while(!Leer.eof())
                    {
                        if(identificador==buscarId)
                        {
                            encontrado=true;
                            cout<<"----------------------------"<<endl;
                            cout<<"palabra1:     "<<palabra1 <<endl;
                            cout<<"palabra2:     "<<palabra2 <<endl;
                            cout<<"identificador:"<<identificador <<endl;
                            cout<<"----------------------------"<<endl;
                            cout<<endl;
                        }
                        Leer>>palabra1>>palabra2>>identificador;
                    }
                    if(encontrado==false)
                    {
                        cout<<"Identificador no encontrado"<<endl;
                    }
                    Leer.close();
                    break;
                }

            case 4:
                {
                    cout << "Ingrese el id del registro a modificar: ";
                    cin >> buscarId;
                    cout << "Ingrese la nueva palabra1: \n";
                    cin >> palabra1sus;
                    cout << "Ingrese la nueva palabra2: \n";
                    cin >> palabra2sus;
                    Temp.open("temporal.txt", ios::out);
                    Leer.open(nombreArchivo, ios::in);
                    while(Leer>>palabra1>>palabra2>>identificador){
                        if(buscarId==identificador){
                            memcpy(palabra1,palabra1sus,sizeof(palabra1sus));
                            memcpy(palabra2,palabra2sus,sizeof(palabra2sus));
                        }
                        Temp << palabra1 << " " << palabra2 << " " << identificador << endl;
                    }
                    Temp.close();
                    Leer.close();
                    remove("Operacion.txt");
                    rename("temporal.txt", "Operacion.txt");
                    cout << "El registro ha sido modificado exitosamente\n\n";
                    break;
                }

            case 5:
                {
                    cout << "Ingrese el id del registro a eliminar: ";
                    cin >> buscarId;
                    Temp.open("temporal.txt", ios::out);
                    Leer.open(nombreArchivo, ios::in);
                    while(Leer>>palabra1>>palabra2>>identificador){
                        if(buscarId!=identificador){
                            Temp << palabra1 << " " << palabra2 << " " << identificador << endl;
                        }
                    }
                    Temp.close();
                    Leer.close();
                    remove("Operacion.txt");
                    rename("temporal.txt","Operacion.txt");
                    cout << "Registro eliminado correctamente\n\n";
                    break;
                }
        }
        if (opcion==6)
            break;
    }
    return 0;
}
