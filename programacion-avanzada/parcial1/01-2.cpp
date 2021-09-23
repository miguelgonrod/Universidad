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
    int i = 0;
    datosPersona datospersona[10];
    while(i<10){
        cout << "Ingrese el nombre de la persona " << i+1 << ": \n";
        getline(cin>>ws,datospersona[i].nombre);
        datospersona[i].inicial = datospersona[i].nombre[0];
        cout << "Ingrese el dia mes y año de nacimiento en forma numerica separados por un espacio:\n";
        cin >> datospersona[i].diaDeNacimiento.dia >> datospersona[i].diaDeNacimiento.mes >> datospersona[i].diaDeNacimiento.anyo;
        cout << "ingrese la nota: ";
        cin >> datospersona[i].nota;
        i++;
    }
    i=0;
    while(i<10){
        cout << "Nombre: " << datospersona[i].nombre << endl;
        cout << "Inicial: " << datospersona[i].inicial << endl;
        cout << "Fecha de nacimiento: " << datospersona[i].diaDeNacimiento.dia << "/" << datospersona[i].diaDeNacimiento.mes << "/" << datospersona[i].diaDeNacimiento.anyo << endl;
        cout << "Nota: " << datospersona[i].nota << "\n\n";
        i++;
    }
    return 0;
}
