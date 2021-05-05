#include <iostream>
using namespace std;

struct Estudiante(){ //estructuras: varias variables en una
    string nombre;
    int edad;
    float notas[5];
}; //obligatorio el ;

int main(){
    int contador, numero, pos;
    Estudiante pepe,juan,jose;
    pepe.nombre = "Pepe";
    pepe.edad = 18;
    pepe.notas[0] = 3.0;
    pepe.notas[1] = 3.5;
    pepe.notas[2] = 2.8;
    pepe.notas[3] = 3.7;
    pepe.notas[4] = 5.0;
    cout << pepe.nombre << " " << pepe.edad;
    getline(cin>>ws, est.nombre); // este acepta palabras separadas con espacio, est.nombre == variable a guardar
    return;
}
