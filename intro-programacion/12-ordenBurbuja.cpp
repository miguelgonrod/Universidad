#include <iostream>
using namespace std;
void OrdenamientoBurbuja(int arreglo[], int tamano);
const int Max_capacidad = 100;
int main(){
    int valores[Max_capacidad];
    int tamano;

    cout << "Cuantos numeros desea ingresar (1->" << Max_capacidad << "): ";
    cin >> tamano;

    if(tamano > Max_capacidad || tamano < 1){
        cout << "Ha ingresado un valor invalido";
        return 0;
    }

    for(int i = 0; i<tamano; i++){
        cout << "Ingrese el numero " << i+1 << ": ";
        cin >> valores[i];
    }
    OrdenamientoBurbuja(valores, tamano);
    return 0;
}

void OrdenamientoBurbuja(int arreglo[], int tamano){
    int aux;
    for(int i = 0; tamano;i++){
        for(int j = 0; j < tamano-1-i; j++){
            if(arreglo[j]>arreglo[j+1]){
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }
    return;
}
