#include <iostream>
using namespace std;
int main(){
    int matriz[3][3], num;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){ // recorre toda la matriz
            cout << "Ingrese el valor de x: " << j+1 << " y: " << i+1 << ":\n";
            cin >> num; // ingresa un valor para la posicion determinada por i y j
            matriz[i][j] = num; // guarda el valor
        }
    }
    cout << "\n\nTraspuesta\n\n";
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++){ // recorre la matriz en vertical para generar la traspuesta
            cout << matriz[i][j] << " "; // imprime el valor
        }
        cout << endl;
    }
    return 0;
}
