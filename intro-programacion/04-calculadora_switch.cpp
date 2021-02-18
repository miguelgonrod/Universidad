#include <iostream>
using namespace std;
int main(){
    float a, b, ans;
    char option;
    cout << "Ingresa el numero de a: ";
    cin >> a;
    cout << "Ingresa el numero de b: ";
    cin >> b;
    cout << "Ingresa que operacion quieres realizar: ";
    cin >> option;
    switch(option){
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            if(b==0){
                cout << "No se puede dividir entre 0";
                return 0;
            }
            else{
                ans = a / b;
                break;
            }
        default:
            cout << "Opcion invalida";
            return 0;
    }
    cout << "La respuesta de " << a << " " << option << " " << b << " = " << ans;
    return 0;
}
