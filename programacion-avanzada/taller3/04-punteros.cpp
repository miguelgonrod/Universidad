#include <iostream>
#include <typeinfo>

using namespace std;

int main(){
    double doble = 7.7265540, *puntDoble=&doble; // Inicializo las variables y sus respectivos punteros apuntando a la direccion de la variable
    bool booleano = true, *puntBooleano=&booleano;
    float flotante = 876.25, *puntFlotante=&flotante;
    int entero = 13, *puntEntero=&entero;
    char caracter = 'm', *puntCaracter=&caracter;

    cout << "+------------+\n" <<
            "|  VARIABLES |\n" <<
            "+------------+\n\n";
    cout << "tipo       direccion       valor    tamaño\n";;
    cout << typeid(doble).name() << "          " << &doble << " " << doble << "   " << sizeof(&doble) <<  endl; // typeid retorna un caracter indicando el tipo de variable & retorna la direccion, luego imprimimos el valor y de ultimo el tamaño
    cout << typeid(booleano).name() << "          " << &booleano << " " << booleano << "         " << sizeof(&booleano) << endl;
    cout << typeid(flotante).name() << "          " << &flotante << " " << flotante << "    " << sizeof(&flotante) << endl;
    cout << typeid(entero).name() << "          " << &entero << " " << entero << "        " << sizeof(&entero) << endl;
    cout << typeid(caracter).name() << "          " << (void *)&caracter << " " << caracter << "         " << sizeof(&caracter) << "\n\n\n";

    cout << "+------------+\n" <<
            "|  PUNTEROS  |\n" <<
            "+------------+\n\n";
    cout << "tipo       direccion       valor           tamaño\n";;
    cout << typeid(puntDoble).name() << "          " << &puntDoble << " " << puntDoble << "  " << sizeof(&puntDoble) <<  endl;
    cout << typeid(puntBooleano).name() << "          " << &puntBooleano << " " << puntBooleano << "  " << sizeof(&puntBooleano) << endl;
    cout << typeid(puntFlotante).name() << "          " << &puntFlotante << " " << puntFlotante << "  " << sizeof(&puntFlotante) << endl;
    cout << typeid(puntEntero).name() << "          " << &puntEntero << " " << puntEntero << "  " << sizeof(&puntEntero) << endl;
    cout << typeid(puntCaracter).name() << "          " << (void *)&puntCaracter << " " << puntCaracter << "               " << sizeof(&puntCaracter) << endl;
    return 0;
}

