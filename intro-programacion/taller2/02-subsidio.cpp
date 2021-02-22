#include <iostream>
using namespace std;
int main(){
    float sueldo, subsidio;
    int edad, numeroHijos;
    cout << "Ingresa tu edad: ";
    cin >> edad;
    cout << "Ingresa de cuanto es tu sueldo: ";
    cin >> sueldo;
    cout << "Ingresa tu numero de hijos: ";
    cin >> numeroHijos;
    if(edad < 30 || edad > 40){
        subsidio = sueldo * 0.5 / 100;
        cout << "Su subsidio es de: " << subsidio << " pesos";
    }
    else{
        subsidio = (sueldo * 3.0 / 100.0) * numeroHijos;
        cout << "Su subsidio es de: " << subsidio << " pesos";
    }
    return 0;
}
