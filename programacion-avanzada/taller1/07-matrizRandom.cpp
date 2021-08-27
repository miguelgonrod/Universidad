#include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL)); // selecciona la semilla del random la cual va a ser el tiempo de nuestro reloj
    int nums[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){ // entre estos dos for recorremos toda la matriz 100 x 100 para guardar un valor
            nums[i][j] = rand() % 1000 + 1; // genera un valor aleatorio entre 1 y 1000
        }
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            cout << nums[i][j] << "  "; // junto con los for imprime todos los valores de la matriz
        }
        cout << "\n";
    }
    return 0;
}
