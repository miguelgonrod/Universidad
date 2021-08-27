#include <iostream>

using namespace std;

void suma(int num1,int num2);
void resta(int num1,int num2);
void multiplicacion(int num1,int num2);
void division(int num1,int num2, int ent1);

int main(){
    int opcion;
    int num1, num2, ent1, *apuntnum1=&num1, *apuntnum2=&num2, *apuntent1=&ent1;
    do{
        cout << "Ingrese una opcion 1)suma 2)resta 3)multiplicacion 4)division 5)salir\n";
        cin >> opcion;
        ent1=0;
        cout << "Ingrese el dividendo y el divisor separados por un espacio: \n";
        cin >> num1 >> num2;
        if(opcion==1){
            suma(*apuntnum1,*apuntnum2);
        }
        else if(opcion==2){
            resta(*apuntnum1,*apuntnum2);
        }
        else if(opcion==3){
            multiplicacion(*apuntnum1,*apuntnum2);
        }
        else if(opcion==4){
            division(*apuntnum1,*apuntnum2,*apuntent1);
        }
    }while(opcion!=5);
    return 0;
}

void suma(int num1,int num2){
    for(int i = 0; i<num2; i++){
        num1++;
    }
    cout << "El resultado es: " << num1 << "\n\n";
    return;
}

void resta(int num1,int num2){
    for(int i = 0; i<num2; i++){
        num1--;
    }
    cout << "El resultado es: " << num1 << "\n\n";
    return;
}

void multiplicacion(int num1,int num2){
    for(int i = 1; i < num2; i++){
        num1+=num2;
    }
    cout << "El resultado es: " << num1 << "\n\n";
    return;
}

void division(int num1,int num2, int ent1){
    if(num2==0){
        cout << "Operacion invalida, es imposible dividir entre 0\n\n";
    }
    else if(num1==0){
        cout << "El resultado es: 0\nEl resto es: 0\n\n";
    }
    else{
        while(true){
            if(num1-num2<0){
                break;
            }
            num1= num1-num2;
            ent1++;
        }
        cout << "El resultado es: " << ent1 << "\nEl resto es: " << num1 << "\n\n";
    }
    return;
}
