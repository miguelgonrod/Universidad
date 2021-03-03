#include <iostream>
using namespace std;
int main(){
    int numero, max = 0, contador = 1, suma = 0;
    cout << "Ingresa el numero para iniciar la granizada: ";
    cin >> numero;
    while(numero == 1){
        cout << "El numero debe ser distinto de 1: ";
        cin >> numero;
    }
    cout << "La granizada de " << numero << " es: ";
    while(numero > 1){
        contador++;
        if(numero > max){
            max = numero;
        }
        suma += numero;
        if(numero % 2 != 0){
            cout << numero << " ";
            numero = (3*numero)+1;
        }
        else{
            cout << numero << " ";
            numero = numero / 2;
        }
    }
    cout << "1";
    suma += 1;
    cout << "\nLa longitud es " << contador << ", el maximo es " << max << ", sumatoria es " << suma;
    return 0;
}
