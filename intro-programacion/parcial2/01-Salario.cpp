#include <iostream>
using namespace std;

int pagar[100];
int cedulas[100];
int salarios[100];
int horasTrabajo[100];
int valorExtra[100];
int cedulasMes[100];
int trabajadas[100];
int finde[100];
int trabajadores;
int persona;
int trabajoMes;

void procesos();
void imprimir();

int main(){
    for(int i = 0; i < 100; i++){
        pagar[i] = 0;
    }
    procesos();
    imprimir();
    return 0;
}

void procesos(){
    cout << "Ingrese el numero de trabajadores de la empresa: ";
    cin >> trabajadores;
    for(int i = 0; i < trabajadores; i++){
        persona=i+1;
        cout << "Ingrese el numero de cedula del trabajador " << persona << ": ";
        cin >> cedulas[i];
        cout << "Ingrese el salario de el trabajador " << persona << ": ";
        cin >> salarios[i];
        cout << "Ingrese las horas maximas de trabajo del trabajador " << persona << ": ";
        cin >> horasTrabajo[i];
        cout << "Ingrese el valor de las horas extra del trabajador " << persona << ": ";
        cin >> valorExtra[i];
    }
    cout << "Cuantos trabajadores trabajaron este mes?: ";
    cin >> trabajoMes;
    for(int i = 0; i < trabajoMes; i++){
        persona = i+1;
        cout << "Ingrese el numero de cedula de el empleado " << persona << ": ";
        cin >> cedulasMes[i];
        cout << "Ingrese las horas trabajadas de el empleado " << persona << ": ";
        cin >> trabajadas[i];
        cout << "Ingrese si el empleado " << persona << " trabajo el fin de semana 0=no 1=si: ";
        cin >> finde[i];
    }
    for(int i = 0; i < trabajoMes; i++){
        int cedulaActual = 0;
        int pagoAct = 0;
        int precioHoraAct = 0;
        int horaAct = 0;
        for(int j = 0; j < trabajadores; j++){
            if(cedulasMes[i] == cedulas[j]){
                cedulaActual = j;
                break;
            }
        }
        precioHoraAct = salarios[cedulaActual]/horasTrabajo[cedulaActual];
        if(trabajadas[i]==horasTrabajo[cedulaActual]){
            pagoAct = salarios[cedulaActual];
        }
        else if(trabajadas[i] < horasTrabajo[cedulaActual]){
            horaAct = horasTrabajo[cedulaActual]-trabajadas[i];
            pagoAct = salarios[cedulaActual]-(horaAct*precioHoraAct);
        }
        else{
            horaAct = trabajadas[i] - horasTrabajo[cedulaActual];
            cout << horaAct << endl;
            pagoAct = salarios[cedulaActual]+(horaAct*valorExtra[cedulaActual]);
        }
        if(finde[i] == 1){
            pagoAct = (pagoAct * 105)/100;
        }
        pagar[i] = pagoAct;
    }
    return;
}

void imprimir(){
    for(int i = 0; i < trabajadores; i++){
        cout << "Cedula: " << cedulas[i] << " Precio a pagar: " << pagar[i] << endl;
    }
    return;
}
