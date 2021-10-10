#include <iostream>
#include <cmath>
using namespace std;

/*
Nombre: binario
Objetivo: recorrer cada digito del numero convirtiendolo en su denominacion binaria
Entradas:  num
Salidas: void
*/

void binario(long int num);

int main(){
    long int num;
    cout << "Ingrese el numero que desea convertir: ";
    cin >> num;
    binario(num);
}

void binario(long int num){
    long double dos = 2;
    if(num < 2){
        cout << num;
        return;
    }
    else{
        binario(num/2);
        cout << fmod(num,2);
        return;
    }
}
