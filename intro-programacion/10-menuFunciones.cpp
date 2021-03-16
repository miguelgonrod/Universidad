#include <iostream>
using namespace std;

int sumatoria(int a, int b);
int factorial(int a, int b);

int main(){
    int opcion = 0, num1, num2, valorRetornado, otraVez;
    while(true){
        cout << "Que opcion deseas usar? 1)salir 2)sumatoria 3)factorial\n";
        cin >> opcion;
        if(opcion == 1){
            break;
        }
        cout << "Ingrese dos numeros separados por un espacio\n";
        cin >> num1 >> num2;
        if(opcion == 2){
            valorRetornado = sumatoria(num1, num2);
        }
        else if(opcion == 3){
            valorRetornado = factorial(num1, num2);
        }
        cout << "El resultado de su operacion es: " << valorRetornado << "\n";
        cout << "Deseas realizar otra operacion? 1)si 2)no\n";
        cin >> otraVez;
        if(otraVez == 2){
            break;
        }
    }
    return 0;
}

int sumatoria(int a, int b){
    int resultado;
    resultado = a + b;
    return resultado;
}

int factorial(int a, int b){
    int resultado = a;
    if (b == 0){
        resultado = 1;
    }
    else{
        for(int i = b; i > 0; i--){
            resultado *= a;
        }
    }
    return resultado;
}
