#include <iostream>
using namespace std;
int main(){
    int opcion, pos, sus, nums[10]={0,0,0,0,0,0,0,0,0,0};
    while(true){
        cout << "Ingrese una opcion 1)Insertar 2)borrar 3)Imprimir 4)insertar-todos 5)borrar-todos 6)Imprimir-todos 7)salir:\n";
        cin >> opcion; // pregunta la opcion a elegir
        switch(opcion){ // para el caso del 1 al 3 revisar el codigo 5
            case 1:
                cout << "Ingrese la posicion a la cual quiere insertar el valor: ";
                cin >> pos; 
                while(pos < 1 || pos > 10){
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "ingrese el numero a colocar: ";
                cin >> sus;
                nums[pos-1] = sus;
                cout << "valor insertado correctamente\n\n";
                break;
            case 2:
                cout << "Ingrese la posicion de la cual quiere borrar el valor:\n";
                cin >> pos;
                while(pos < 1 || pos > 10){
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                nums[pos-1] = 0;
                cout << "Valor borrado correctamente\n\n";
                break;
            case 3:
                cout << "Ingrese la posicion de la cual quiere mostrar el valor:\n";
                cin >> pos;
                while(pos < 1 || pos > 10 ){
                    cout << "opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "valor: " << nums[pos-1] << "\n\n";
                break;
            case 4:
                for(int i = 0; i < 10; i++){ // inicia un bucle para guardar los 10 valores en el vector
                    cout << "Ingrese el valor de la posicion " << i+1 << ": ";
                    cin >> sus;
                    nums[i] = sus;
                }
                cout << "Numeros insertados correctamente\n";
                break;
            case 5:
                for(int i = 0; i < 10; i++){ // inicia un bucle que borra los 10 valores del vector
                    nums[i] = 0;
                }
                cout << "numeros borrados correctamente\n";
                break;
            case 6:
                for(int i = 0; i < 10; i++){ // inicia un bucle que imprime todos los valores del vector
                    cout << nums[i] << " ";
                }
                cout << "\n\n";
                break;
            case 7:
                break;
            default:
                cout << "opcion invalida, ingrese otra de nuevo\n";
                break;
        }
        if(opcion == 7){
            break;
        }
    }
    return 0;
}
