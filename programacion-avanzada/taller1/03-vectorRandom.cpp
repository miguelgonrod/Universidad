#include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int nums[100], pos;
    for(int i = 0; i < 100; i++){ // genera un numero aleatorio entre 1 y 1000000 diferente para cada uno de los 100 valores del vector
        nums[i]=rand() % 1000000 + 1;
    }
    while(true){
        cout << "Ingresa la posicion a la cual quieres revisar el numero 1-100 (valor negativo acaba el programa):\n";
        cin >> pos; // pregunta la posicion a la cual quiere ver el valor o en su defecto acaba el programa
        if(pos < 0){
            break;
        }
        else if(pos <= 100){
            cout << nums[pos-1] << endl; // imprime el valor
        }
        else{
            cout << "posicion invalida\n";
        }
    }
    return 0;
}
