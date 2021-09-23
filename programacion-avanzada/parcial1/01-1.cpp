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
    string nombres;
    datosPersona datospersona, *puntero_datospersona=&datospersona;
    cout << "Ingrese el nombre: \n";
    getline(cin>>ws,nombres);
    puntero_datospersona->nombre = nombres;
    puntero_datospersona->inicial = puntero_datospersona->nombre[0];
    cout << "Ingrese el dia mes y año de nacimiento separados por un espacio:\n";
    cin >> puntero_datospersona->diaDeNacimiento.dia >> puntero_datospersona->diaDeNacimiento.mes >> puntero_datospersona->diaDeNacimiento.anyo;
    cout << "Ingrese la nota: ";
    cin >> puntero_datospersona->nota;
    cout << endl << endl;
    cout << "Nombre: " << puntero_datospersona->nombre << endl;
    cout << "Inicial: " << puntero_datospersona->inicial << endl;
    cout << "Fecha de nacimiento: " << puntero_datospersona->diaDeNacimiento.dia << "/" << puntero_datospersona->diaDeNacimiento.mes << "/" << puntero_datospersona->diaDeNacimiento.anyo << endl;
    cout << "Nota: " << puntero_datospersona->nota;
    return 0;
}
