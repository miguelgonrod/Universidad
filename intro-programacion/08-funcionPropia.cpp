#include <iostream>
using namespace std;

// prototipo
int mayor(int a, int b);

int main(){
    int num1, num2;
    cout << "Ingrese dos numeros separados por un espacio: ";
    cin >> num1 >> num2;
    cout << "El numero mayor es: " << mayor(num1, num2);
    return 0;
}

int mayor(int a, int b){  // funciones siempre por debajo de main
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
