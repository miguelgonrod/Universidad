#include <iostream>
using namespace std;
int main(){
    while(true){
        int number;
        string again;
        cout << "Ingresa el numero que quieres usar como maximo: ";
        cin >> number;
        while(number > 0){
           cout << number;
           number--;
           cout << "\n";
        }
        cout << "Quieres escribir otro numero?\n";
        cin >> again;
        if(again == "si" || again == "Si" || again == "SI"){
        }
        else{
            break;
        }
    }
    return 0;
}
