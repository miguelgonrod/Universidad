#include <iostream>
using namespace std;
int main(){
    int opcion, pos, sus, nums[10]={0,0,0,0,0,0,0,0,0,0};
    while(true){
        cout << "Ingrese una opcion 1)Insertar 2)borrar 3)Imprimir 4)salir:\n";
        cin >> opcion; // pregunta la opcion a elegir
        switch(opcion){
            case 1:
                cout << "Ingrese la posicion a la cual quiere insertar el valor: ";
                cin >> pos; // pregunta la posicion donde se va a guardar el valor
                while(pos < 1 || pos > 10){ // en caso de una posicion invalida
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "ingrese el numero a colocar: ";
                cin >> sus; // ingresa el valor a guardar
                nums[pos-1] = sus; // guarda el valor en la posicion ingresada
                cout << "valor insertado correctamente\n\n";
                break;
            case 2:
                cout << "Ingrese la posicion de la cual quiere borrar el valor:\n";
                cin >> pos; // pregunta la posicion del valor a borrar
                while(pos < 1 || pos > 10){
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                nums[pos-1] = 0; // borra el valor volviendolo 0
                cout << "Valor borrado correctamente\n\n";
                break;
            case 3:
                cout << "Ingrese la posicion de la cual quiere mostrar el valor:\n";
                cin >> pos; // pregunta la posicion del valor a mostrar
                while(pos < 1 || pos > 10 ){
                    cout << "opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "valor: " << nums[pos-1] << "\n\n"; // imprime el valor
                break;
            case 4:
                break;
            default:
                cout << "opcion invalida, ingrese otra de nuevo\n";
                break;
        }
        if(opcion == 4){ // cierra el programa
            break;
        }
    }
    return 0;
}
