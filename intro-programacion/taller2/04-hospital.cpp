#include <iostream>
using namespace std;
int main(){
    int edad, tipoEnfermedad, dias;
    float costo;
    cout << "Ingrese la edad del paciente: ";
    cin >> edad;
    cout << "Ingrese el tipo de enfermedad del paciente: ";
    cin >> tipoEnfermedad;
    cout << "Ingrese cuantos dias va a estar hospitalizado el paciente: ";
    cin >> dias;
    switch(tipoEnfermedad){
        case 1:
            costo = (dias * 25);
            break;
        case 2:
            costo = (dias * 16);
            break;
        case 3:
            costo = (dias * 20);
            break;
        case 4:
            costo = (dias * 32);
            break;
        default:
            cout << "Opcion invalida, tipo de enfermedad inexistente";
            break;
    }
    if(edad >= 14 && edad <= 22){
        costo = costo * 1.1;
    }
    cout << "El costo de la hospitalizacion del paciente por " << dias << " dias es de " << costo;
    return 0;
}
