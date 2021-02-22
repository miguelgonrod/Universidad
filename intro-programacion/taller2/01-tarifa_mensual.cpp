#include <iostream>
using namespace std;
int main(){
    float minutos, tarifaMensual;
    const int valorNormal = 100;
    const int valorAlterado = 40;
    const int tarifaBasica = 50000;
    cout << "Ingrese los minutos consumidos: ";
    cin >> minutos;
    if(minutos > 500){
        tarifaMensual = ((minutos-500)*40)+(500*100)+50000;
    }
    else if(minutos<0){
        cout << "Opcion invalida";
        return 0;
    }
    else{
        tarifaMensual = (minutos * 100) + 50000;
    }
    cout << "Su tarifa mensual es de: " << tarifaMensual << " pesos";
    return 0;
}
