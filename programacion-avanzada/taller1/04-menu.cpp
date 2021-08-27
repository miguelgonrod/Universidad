#include <iostream>
#include <ctime>
using namespace std;

void delay(int secs);

int main(){
    int opcion;
    while(true){
        cout << "Ingrese una opcion 1)insertar 2)borrar 3)imprimir 4)salir: ";
        cin >> opcion; // pregunta la opcion a elegir
        switch(opcion){
            case 1:
                cout << "ahorita te inserto el valor\n";
                delay(3); // espera 3 secs, igual con todos los delay
                break;
            case 2:
                cout << "Ahorita te borro el valor\n";
                delay(3);
                break;
            case 3:
                cout << "Ahorita te imprimo el valor\n";
                delay(3);
                break;
            case 4:
                break;
            default:
                cout << "opcion invalida\n";
                break;
        }
        if(opcion == 4){
            break; // termina el codigo
        }
    }
    return 0;
}

void delay(int secs){ // esta funcion aprovecha un bucle for y el valor de la funcion time para generar un delay
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
    return;
}
