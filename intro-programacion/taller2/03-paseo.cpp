#include <iostream>
using namespace std;
int main(){
    const int valorPersona = 15000;
    const int transporte = 192000;
    int personas;
    float cTotal, cPersona, total, residuo, alimentacion, museo;
    cout << "Ingresa la cantidad de personas: ";
    cin >> personas;
    if (personas < 0){
        cout << "Opcion invalida";
        return 0;
    }
    else if(personas == 0){
        cout << "Tu ganancia es de 0";
        return 0;
    }
    else if(personas < 20 && personas > 0){
        alimentacion = personas * 5000.0;
    }
    else{
        alimentacion = personas * 1000.0; 
    }
    if(personas >= 25){
        museo = personas * 900.0;
    }
    else{
        museo = personas * 3000;
    }
    total = valorPersona * personas;
    cTotal = transporte + alimentacion + museo;
    cPersona = cTotal / personas;
    residuo = total - cTotal;
    if(residuo < 0){
        cout << "Tuviste una perdida de " << (residuo*-1) << " pesos";
    }
    else if(residuo > 0){
        cout << "Tuviste una ganancia de " << residuo << " pesos";
    }
    else{
        cout << "No tuviste ganancia alguna";
    }
    return 0;
}
