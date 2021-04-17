#include <iostream>
using namespace std;

const int Max_capacidad = 50;
void valores(int cosecha[], string nombres[]);
void calculos(int cosecha[], int tamano);
void eliminar(int cosecha[], string nombres[], int tamano);
int noGanancia(int cosecha[], string nombres[], int tamano);
int tamanonono = 0;

int main(){
    string nombres[Max_capacidad];
    int cosecha[Max_capacidad];
    valores(cosecha, nombres);
    calculos(cosecha, tamanonono);
    eliminar(cosecha, nombres, tamanonono);
    noGanancia(cosecha, nombres, tamanonono);
    return 0;

}

void valores(int cosecha[], string nombres[]){
    int tamano=0;
    cout << "Ingrese el numero de parcelas entre 1 y 50: ";
    cin >> tamano;
    tamanonono = tamano;
    while(tamano < 1 || tamano > 50){
        cout << "Ingrese un valor valido: ";
        cin >> tamano;
    }

    for(int i = 0; i < tamano; i++){
        cout << "Ingresa el nombre y las toneladas de la parcela " << i+1 << " separadas por un espacio\n";
        cin >> nombres[i] >> cosecha[i];
    }

    for(int i = 0; i < tamano; i++){
        cout << nombres[i] << ": " << cosecha[i] << "\n";
    }
    return;
}

void calculos(int cosecha[], int tamano){
    int ganancias = 0;
    float promedio = 0;
    for(int i = 0; i < tamano; i++){
        ganancias+=cosecha[i];
        promedio+=cosecha[i];
    }
    promedio /= tamano;
    cout << "ganancias: " << ganancias << " naranjas\npromedio: " << promedio << " naranjas\n";
    return;
}

void eliminar(int cosecha[], string nombres[], int tamano){
    int datoEliminar = 0;
    cout << "Que posicion desea eliminar?\n";
    cin >> datoEliminar;
    while(datoEliminar < 1 || datoEliminar > tamano){
        cout << "Ingrese un valor valido\n";
        cin >> datoEliminar;
    }
    datoEliminar--;
    for(int i = datoEliminar; i < tamano; i++){
        cosecha[i] = cosecha[i+1];
        nombres[i] = nombres[i+1];
    }
    cosecha[tamano-1] = 0;
    nombres[tamano-1] = "0";
    tamanonono--;
    return;
}

int noGanancia(int cosecha[], string nombres[], int tamano){
    int pos0 = -1;
    for(int i = 0; i < tamano-1; i++){
        if(cosecha[i] == 0){
            pos0 = i;
            break;
        }
    }
    if(pos0 >= 0){
        cout << nombres[pos0] << ": " << cosecha[pos0] << " naranjas\n";
        return 0;
    }
    else{
        cout << "Todos tuvieron una produccion mayor a 0 toneladas\n";
        return -1;
    }
}
