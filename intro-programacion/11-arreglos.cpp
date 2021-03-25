#include <iostream>
using namespace std;
int main(){
    int nums[10]={0};
    int buscar;
    cout << "Ingrese 10 numeros separados por un enter\n";
    for(int i = 0; i < 10; i++){
        cin >> nums[i];
    }
    cout << "que numero desea buscar?\n";
    cin >> buscar;
    for(int i = 0; i <= 10; i++){
        if(nums[i]==buscar){
            cout << "El numero " << buscar << " está en la posicion " << i << endl;
            break;
        }
    }
    return 0;
}
