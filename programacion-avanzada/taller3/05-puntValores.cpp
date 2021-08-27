#include <iostream>

using namespace std;

int main(){
    int opcion;
    int ent1, ent2, *puntent1=&ent1, *puntent2=&ent2;
    float float1,float2, *puntfloat1=&float1, *puntfloat2=&float2;
    double dou1, dou2, *puntdou1=&dou1, *puntdou2=&dou2;
    do{
        cout << "Ingresa una opcion 1)enteros 2)flotantes 3)dobles 4)salir: \n";
        cin >> opcion;
        while(opcion < 1 || opcion > 4){
            cout << "Ingrese una opcion valida\n";
            cin >> opcion;
        }
        if(opcion==1){
            cout << "ingrese el primer valor: ";
            cin >> *puntent1;
            cout << "Ingrese el segundo valor: ";
            cin >> *puntent2;
            cout << "\nValor primer puntero: " << *puntent1 << "\nDireccion primer puntero: " << &*puntent1 << endl;
            cout << "\nValor segundo puntero: " << *puntent2 << "\nDireccion segundo puntero: " << &*puntent2 << "\n\n";
        }
        else if(opcion==2){
            cout << "ingrese el primer valor: ";
            cin >> *puntfloat1;
            cout << "Ingrese el segundo valor: ";
            cin >> *puntfloat2;
            cout << "\nValor primer puntero: " << *puntfloat1 << "\nDireccion primer puntero: " << &*puntfloat1 << endl;
            cout << "\nValor segundo puntero: " << *puntfloat2 << "\nDireccion segundo puntero: " << &*puntfloat2 << "\n\n";
        }
        else if(opcion==3){
            cout << "ingrese el primer valor: ";
            cin >> *puntdou1;
            cout << "Ingrese el segundo valor: ";
            cin >> *puntdou2;
            cout << "\nValor primer puntero: " << *puntdou1 << "\nDireccion primer puntero: " << &*puntdou1 << endl;
            cout << "\nValor segundo puntero: " << *puntdou2 << "\nDireccion segundo puntero: " << &*puntdou2 << "\n\n";
        }
    }while(opcion!=4);
    return 0;
}
