#include <iostream>
using namespace std;
int main(){
    int number;
    cout << "Ingresa un numero: ";
    cin >> number;
    for(int i = number; i > 0; i--){
        cout << i << "\n";
    }
    return 0;
}
