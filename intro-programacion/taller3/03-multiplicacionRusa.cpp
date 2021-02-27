#include <iostream>
using namespace std;
int main(){
    int multiplicador, multiplicando, suma = 0;
    cout << "Ingrese el multiplicador: ";
    cin >> multiplicador;
    cout << "Ingrese el multiplicando: ";
    cin >> multiplicando;
    while(multiplicador >= 1){
        if(multiplicador % 2 != 0){
            suma += multiplicando;
        }
        multiplicador = multiplicador/2;
        multiplicando = multiplicando * 2;
    }
    cout << "El resultado es: " << suma;
    return 0;
}
