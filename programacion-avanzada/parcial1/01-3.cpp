#include <iostream>
using namespace std;

struct fechaNacimiento{
    int dia;
    int mes;
    int anyo;
};

struct datosPersona{
    string nombre;
    char inicial;
    fechaNacimiento diaDeNacimiento;
    float nota;
};

int main(){
    datosPersona datospersona;
    cout << "Ingresa un nombre: \n";
    getline(cin>>ws,datospersona.nombre);
    datospersona.inicial = datospersona.nombre[0];
    cout << "Ingresa el dia mes y año de nacimiento separados por un espacio: ";
    cin >> datospersona.diaDeNacimiento.dia >> datospersona.diaDeNacimiento.mes >> datospersona.diaDeNacimiento.anyo;
    cout << "Ingrese la nota: ";
    cin >> datospersona.nota;
    cout << "\n\n";
    cout << "Nombre: " << datospersona.nombre << endl;
    cout << "Inicial: " << datospersona.inicial << endl;
    cout << "Fecha de nacimiento: " << datospersona.diaDeNacimiento.dia << "/" << datospersona.diaDeNacimiento.mes << "/" << datospersona.diaDeNacimiento.anyo << endl;
    cout << "Nota: " << datospersona.nota;
    return 0;
}
