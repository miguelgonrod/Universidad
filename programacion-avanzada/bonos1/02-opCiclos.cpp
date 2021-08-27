#include <iostream>
using namespace std;

void suma();
void resta();
void multiplicacion();
void division();

float num1, num2, res=0;

int main(){
    int opcion;
    do{
        res=0;
        cout << "Ingrese una opcion 1)suma 2)resta 3)multiplicacion 4)division 5)salir\n";
        cin >> opcion;
        while(opcion<1||opcion>5){
            cout << "Ingrese una opcion valida\n";
            cin >> opcion;
        }
        switch(opcion){
            case 1:
                suma();
                break;
            case 2:
                resta();
                break;
            case 3:
                multiplicacion();
                break;
            case 4:
                division();
                break;
        }
    }while(opcion!=5);
    return 0;
}

void suma(){ // funcion que suma numeros decimales
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese un segundo numero: ";
    cin >> num2;
    cout << "El resultado de la suma es: " << num1+num2 << "\n\n";
    return;
}

void resta(){ // funcion que resta numeros decimales
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese un segundo numero: ";
    cin >> num2;
    cout << "El resultado es: " << num1-num2 << "\n\n";
    return;
}

void multiplicacion(){ // funcion que multiplica decimales
    cout << "Ingresa el primer numero: ";
    cin >> num1;
    cout << "Ingresa el segundo numero(positivo): ";
    cin >> num2;
    if(num1==0||num2==0){ // en caso de multiplicar por 0
        cout << "El resultado es 0 \n\n";
    }
    else{
        while(num2<0){
            cout << "Ingresa un numero positivo: ";
            cin >> num2;
        }
        num1*=10000; // estas cuatro lineas convierte el numero1 y numero2 ambos decimales junto con 4 decimales en uno entero
        num1=int(num1);
        num2*=10000;
        num2=int(num2);
        for(int i = 0; i < num2; i++){ // hace la multiplicacion
            res+=num1;
        }
        cout << "El resultado es: " << res/100000000 << "\n\n"; // se divide entre 1 con 8 ceros ya que en multiplicacion se suma la cantidad de decimales (4+4=8)
    }
    return;
}

void division(){ // funcion para dividir
    int mult = 0; 
    cout << "Ingrese un numero: ";
    cin >> num1;
    while(num1<0){
        cout << "No ingrese valores negativos: ";
        cin >> num1;
    }
    cout << "Ingrese otro numero: ";
    cin >> num2;
    while(num2==0){
        cout << "No se puede dividir entre 0, ingrese un valor valido: ";
        cin >> num2;
    }
    while(num2<0){
        cout << "No ingrese valores negativos: ";
        cin >> num2;
    }
    if(num1==0){
        cout << "El resultado es 0\n\n";
    }
    else{
        while(true){ // busca un numero que multiplicado por el divisor sea menor al dividendo y si le agrego 1 al divisor se pase
            if(mult*num2<num1&&(mult+1)*num2>num1){
                break;
            }
            else{
                mult++;
            }
        }
        cout << "Entero: " << mult << "\nResto: " << num1-(num2*mult) << "\n\n";
    }
    return;
}
