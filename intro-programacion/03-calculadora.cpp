#include <iostream>
using namespace std;
int main()
{
    float a, b, ans;
    char option;
    cout << "ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Que operacion quiere realizar?: ";
    cin >> option;
    if(option == '+'){
        ans = a + b;
    }
    else if (option == '-'){
        ans = a - b;
    }
    else if (option == '*'){
        ans = a * b;
    }
    else if (option == '/' and b == 0){
        cout << "No se puede dividir entre 0";
        return 0;
    }
    else if (option == '/' and b != 0){
        ans = a / b;
    }
    else{
        cout << "Opcion invalida";
        return 0;
    }
    cout << "La operacion de " << a << " " << option << " " << b << " = " << ans;
    return 0;
}
