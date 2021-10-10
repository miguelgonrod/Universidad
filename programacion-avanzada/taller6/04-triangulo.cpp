#include <iostream>
using namespace std;


/*
Nombre: suma
Objetivo: ir haciendo las sumas en el orden debido e imprimir los resultados
Entradas:  arreglo[], longitud, num
Salidas: void 
*/
void suma(int arreglo[], int longitud, int num);

int main(){
    int num, longitud;
    cout << "Cuantos numeros desea ingresar?: ";
    cin >> num;
    int arreglo[num];
    for(int i = 0; i < num; i++){
        cout << "Ingresa el numero " << i+1 << ": ";
        cin >> arreglo[i];
    }
    cout << "El triangulo de suma es:\n";
    suma(arreglo, longitud, num);
    return 0;
}

void suma(int arreglo[], int longitud, int num){
    int nuarreglo[num-1];
    for(int i = 0; i < num-1; i++){
        cout << arreglo[i] << " + " << arreglo[i+1] << " = " << arreglo[i]+arreglo[i+1] << endl;
        nuarreglo[i]=arreglo[i]+arreglo[i+1];
    }
    cout << "\n\n";
    if(num>1){
        suma(nuarreglo, longitud, num-1);
    }
    else if(num==1){
        cout << arreglo[0];
        return;
    }
    else{
        return;
    }
}
