#include <iostream>
using namespace std;
int main(){
    int mayor, menor, numero;
    string opcion;
    cout << "Ingresa un numero: ";
    cin >> numero;
    mayor = numero;
    menor = numero;
    cout << "Quieres ingresar otro numero? (si/no) ";
    cin >> opcion;
    while(opcion != "no"){
        cout << "Ingresa otro numero: ";
        cin >> numero;
        if(numero > mayor){
            mayor = numero;
        }
        else if(numero < menor){
            menor = numero;
        }
        cout << "Quieres ingresar otro numero? (si/no)";
        cin >> opcion;
    }
    cout << "El numero mayor fue: " << mayor;
    cout << "\nEl numero menor fue: " << menor;
    return 0;
}
