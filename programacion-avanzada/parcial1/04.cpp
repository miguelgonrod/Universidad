#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void introducir_caracter();
void tamaño();
void intercambiar();
void sumarCadenas();
void invertir();

int main(){
    int opcion;
    do{
        cout << "Ingrese una opcion 1)introducir-caracter 2)cambiar-tamaño 3)intercambiar 4)sumar-cadenas 5)Invertir-cadena 6)salir\n";
        cin >> opcion;
        while(opcion < 1 || opcion > 6){
            cout << "Ingrese una opcion valida:\n";
            cin >> opcion;
        }
        switch(opcion){
            case 1:
                introducir_caracter();
                break;
            case 2:
                tamaño();
                break;
            case 3:
                intercambiar();
                break;
            case 4:
                sumarCadenas();
                break;
            case 5:
                invertir();
                break;
        }
    }while(opcion!=6);
    return 0;
}

void introducir_caracter(){
    string cadena;
    char caracter;
    cout << "Ingrese una cadena de texto: ";
    getline(cin>>ws,cadena);
    cout << "Ingrese el caracter: ";
    cin >> caracter;
    cadena+=caracter;
    cout << "La frase quedó: " << cadena << "\n\n";
    return;
}

void tamaño(){
    string cadena;
    int tam;
    cout << "Ingrese la cadena de texto: ";
    getline(cin>>ws, cadena);
    cout << "Ingrese el tamaño: ";
    cin >> tam;
    while(tam>sizeof(cadena)){
        cout << "Ingrese un valor menor al tamaño de la cadena: ";
        cin >> tam;
    }
    cadena.erase(tam);
    cout << "Cadena: " << cadena << endl;
    return;
}

void intercambiar(){
    string cadena1, cadena2, temp;
    cout << "Ingresa la primer cadena: ";
    getline(cin>>ws,cadena1);
    cout << "Ingresa la segunda cadena: ";
    getline(cin>>ws,cadena2);
    temp=cadena1;
    cadena1 = cadena2;
    cadena2 = temp;
    cout << "\nCadena 1: " << cadena1 << endl;
    cout << "Cadena 2: " << cadena2 << "\n\n";
    return;
}

void sumarCadenas(){
    string cadena1, cadena2;
    cout << "Ingresa la primer cadena: ";
    getline(cin>>ws,cadena1);
    cout << "Ingresa la segunda cadena: ";
    getline(cin>>ws,cadena2);
    cadena1.append(cadena2);
    cout << "Cadena final: " << cadena1 << "\n\n";
    return;
}

void invertir(){
    string cadena;
    cout << "Ingrese la cadena a invertir: ";
    getline(cin>>ws,cadena);
    reverse(cadena.begin(), cadena.end());
    cout << "Cadena invertida: " << cadena << "\n\n";
    return;
}
