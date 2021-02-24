#include <iostream>
using namespace std;
int main(){
    int floors;
    cout << "Cuantos pisos quieres que tenga la piramide?\n";
    cin >> floors;
    cout << "\n";
    for(int i = 1; i <= floors; i++){
        for(int j = 1; j <= i; j++){
            cout << "*" << " ";
        }
        cout << "\n";
    }
    return 0;
}
