#include <iostream>
using namespace std;
int main(){
    int numero, contador = 1;
    cout << "Ingresa el numero maximo de valores en la piramide: ";
    cin >> numero;
    for(int i = 1; i<=numero;i++){
        for(int j = i; j <= numero; j++){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
