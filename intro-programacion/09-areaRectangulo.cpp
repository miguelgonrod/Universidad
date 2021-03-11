#include <iostream>
using namespace std;

float area(float a, float b);

int main(){
    float base, altura;
    cout << "Ingresa el tamaño de la base en cm: ";
    cin >> base;
    cout << "Ingresa el tamaño de la altura en cm: ";
    cin >> altura;
    cout << "El area del rectangulo es: " << area(base, altura) << " cm";
    return 0;
}

float area(float a, float b){
    return (a*b);
}
