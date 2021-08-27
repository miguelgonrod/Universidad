#include <iostream>
using namespace std;
int main(){
    int numeros[10]={0,0,0,0,0,0,0,0,0,0}, num, pos;
    while(true){
        cout << "Ingrese un numero: ";
        cin >> num; // pregunta el numero a guardar
        cout << "Ingrese una posicion entre 1 y 10 (un negativo cierra el programa)\n";
        cin >> pos; // pregunta la posicion a guardar o en su defecto si quiere acabar el codigo
        if(pos < 0){
            break; // cierra el ciclo para acabar el codigo
        }
        else{
            numeros[pos-1] = num; // guarda el valor ingresado en la posicion ingresada
        }
    }
    for(int i = 0; i < 10; i++){
        cout << numeros[i] << " "; // imprime los valores dentro de el vector
    }
    return 0;
}
