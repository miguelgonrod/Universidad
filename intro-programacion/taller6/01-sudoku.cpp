#include <iostream>
using namespace std;

int sudoku[9][9];

void ingresoDatos();
bool revisarValidez();

int main(){
    ingresoDatos();
    if(revisarValidez() == true){
        cout << "El sudoku sirve";
    }
    else{
        cout << "El sudoku no sirve";
    }
    return 0;
}

void ingresoDatos(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << "Ingrese el valor de la posicion [" << i << "," << j << "]: ";
            cin >> sudoku[j][i];
            while(sudoku[j][i] < 1 || sudoku[j][i] > 9){
                cout << "Ingrese el valor de la posicion [" << i << "," << j << "](1 a 9): ";
                cin >> sudoku[j][i];
            }
        }
    }
    return;
}

bool revisarValidez(){
    int pruebaDatos[9];
    bool valida = true;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            pruebaDatos[j] = sudoku[i][j];
        }

        for(int j = 0; j < 9; j++){
            for(int z = 0; z < 9; z++){
                if(pruebaDatos[j] == pruebaDatos[z] && j != z){
                    valida = false;
                    break;
                }
            }
            if(valida == false){
                break;
            }
        }
    }
    
    if(valida == true){
        for(int j = 0; j < 9; j++){
            for(int i = 0; i < 9; i++){
                pruebaDatos[i] = sudoku[i][j];
            }

            for(int i = 0; i < 9; i++){
                for(int z = 0; z < 9; z++){
                    if(pruebaDatos[i] == pruebaDatos[z] && i != z){
                        break;
                        valida = false;
                        break;
                    }
                }
                if(valida == false){
                    break;
                }
            }
        }
    }
    return valida;
}
