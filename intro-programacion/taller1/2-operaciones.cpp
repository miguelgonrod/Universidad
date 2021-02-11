#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float num1, num2;
    cout << "Ingresa un numero: \n";
    cin >> num1;
    cout << "Ingresa otro numero: \n";
    cin >> num2;
    cout << "Suma: " << num1 << " + " << num2 << " = " << num1 + num2;
    cout << "\nResta: " << num1 << " - " << num2 << " = " << num1 - num2;
    cout << "\nMultiplicacion: " << num1 << " * " << num2 << " = " << num1 * num2;
    cout << "\nDivision: " << num1 << " / " << num2 << " = " << num1 / num2;
    cout << "\nPotencia: " << num1 << " ^ " << num2 << " = " << pow(num1,num2);
    return 0;
}
