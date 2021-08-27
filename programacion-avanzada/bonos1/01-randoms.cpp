#include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL)); // le da la seed a random
    int arreglo[100], max, min, moda = 0;
    float media=0, mediana, arrmoda[100];
    for(int i = 0; i < 100; i++){ //vacia el arreglo arrmoda
        arrmoda[i]=0;
    }
    for(int i = 0; i < 100; i++){ // genera 100 numero aleatorios que almacena en la variable
        arreglo[i]=rand() % 100;
        if(i==0){
            max=arreglo[i];
            min=arreglo[i];
        }
        if(arreglo[i]>max){ // busca el numero maximo
            max=arreglo[i];
        }
        else if(arreglo[i]<min){ // busca el numero minimo
            min=arreglo[i];
        }
        media+=arreglo[i]; // va sumando para sacar la media
        arrmoda[arreglo[i]]++; // va sumando cuantas veces se ha repetido un numero
    }
    media=media/100; // genera la media real
    mediana=(arreglo[49]+arreglo[50])/2; // busca y calcula la mediana
    for(int i = 0;i<100;i++){ // selecciona cual es la moda
        if(i==0){
            moda=i;
        }
        if(arrmoda[i]>arrmoda[moda]){
            moda=i;
        }
    }
    cout << "Maximo: " << max << "\nMinimo: " << min << "\nMedia: " << media << "\nMediana: " << mediana << "\nModa: " << moda;
    return 0;
}
