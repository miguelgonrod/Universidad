#include <iostream>
using namespace std;

void OrdenamientoAs(int arreglo[]);
void OrdenamientoDes(int arreglo[]);

int main(){
    int opcion, vec[7]={0,0,0,0,0,0,0}, num;
    while(true){
        cout << "Ingresa la opcion 1)Ingresar datos 2)Ordenar-ascendente 3)Ordenar-descendente 4)Imprimir 5)salir :\n";
        cin >> opcion; // ingresa la opcion a elegir
        switch(opcion){
            case 1:
                for(int i = 0; i < 7; i++){ // recorre todo el vector preguntando que valor ingresar
                    cout << "Ingrese el valor de la posicion " << i+1 << ": ";
                    cin >> num; // pregunta el valor
                    vec[i]=num; // almacena el valor
                }
                cout << "valores ingresados correctamente\n\n";
                break;
            case 2:
                OrdenamientoAs(vec); // llama a la funcion de ordenar ascendente
                cout << "Valores ordenados correctamente\n\n";
                break;
            case 3:
                OrdenamientoDes(vec); // llama a la funcion de ordenar descendente
                cout << "Valores ordenados correctamente\n\n";
                break;
            case 4:
                for(int i = 0; i < 7; i++){ // recorre todo el vector imprimiendo cada uno de sus valores
                    cout << vec[i] << "  ";
                }
                cout << "\n\n";
                break;
            case 5:
                break;
            default:
                cout << "Opcion incorrecta, ingrese otra nuevamente\n";
                break;
        }
        if(opcion==5){
            break;
        }
    }
    return 0;
}

void OrdenamientoAs(int arreglo[]){
    int aux;
    for(int i = 0; i < 7; i++){ // recorre el vector
        for(int j = 0; j < 7-1-i; j++){ // recorre el vector de abajo hacia arriba desde el valor de la posicion i
            if(arreglo[j] > arreglo[j+1]){ // si el valor actual es mayor al valor siguiente
                aux = arreglo[j]; // guarda el valor actual en aux
                arreglo[j] = arreglo[j+1]; // guarda el valor siguiente en la posicion actual
                arreglo[j+1] = aux; // guarda el valor de aux en la proxima posicion
            }
        }
    }
    return;
}

void OrdenamientoDes(int arreglo[]){
    int aux;
    for(int i = 0; i < 7; i++){ // recorre todo el vector
        for(int j = 0; j < 7-1-i; j++){ // recorre el vector de abajo hacia arriba desde el valor de la posicion i
            if(arreglo[j] < arreglo[j+1]){ // si el valor actual es menor al valor siguiente
                aux = arreglo[j]; // guarda el valor actual en la variable aux
                arreglo[j] = arreglo[j+1]; // guarda el valor siguiente en la posicion actual
                arreglo[j+1] = aux; // guarda en la posicion siguiente el valor en la variable aux
            }
        }
    }
    return;
}
