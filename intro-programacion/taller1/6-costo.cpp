#include <iostream>
using namespace std;
int main()
{
    float precio, cuotaInicial, cuotaMensual;
    cout << "Ingresa el precio del posgrado: \n";
    cin >> precio;
    cuotaInicial = precio * 0.20;
    precio -= cuotaInicial;
    cuotaMensual = precio / 24;
    cout << "La cuota inicial sería de: " << cuotaInicial << " pesos\n";
    cout << "La cuota mensual sería de: " << cuotaMensual << " pesos";
    return 0;
}
