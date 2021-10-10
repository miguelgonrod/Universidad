#include <iostream>
using namespace std;

/*
Nombre: max_min
Objetivo: buscar el maximo y el minimo de un arreglo
Entradas:  arr[], max, min, num, act
Salidas: void
*/

void max_min(int arr[],int max, int min, int num, int act);

int main(){
    int num, max, min, act=0;
    cout << "Ingrese la cantidad de numeros que desea ingresar:\n";
    cin >> num;
    while(num<=0){
        cout << "Ingrese un valor mayor a 0";
        cin >> num;
    }
    int arr[num];
    for(int i = 0; i < num; i++){
        cout << "Ingrese el numero " << i+1 << ": ";
        cin >> arr[i];
    }
    max = arr[0];
    min = arr[0];
    max_min(arr, max, min, num, act);
    return 0;
}

void max_min(int arr[], int max, int min, int num, int act){
    if(act<num){
        if(arr[act]>max){
            max = arr[act];
        }
        else if(arr[act]<min){
            min = arr[act];
        }
        cout << "max: " << max << " i: " << act << endl;
        max_min(arr, max, min, num, act+1);
    }
    else{
        cout << "Maximo: " << max << "\nMinimo: " << min << endl;
        return;
    }
}
