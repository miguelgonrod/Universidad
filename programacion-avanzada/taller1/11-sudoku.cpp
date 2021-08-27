#include <iostream>
#include <time.h>
using namespace std;

int sudoku[4][4];

bool revisarValidez();

int main(){
    srand(time(NULL));
    int pos, num, opcion, comp[4]={0,0,0,0}, compPos[4]={0,0,0,0}, base[2][4];
    while(true){
        cout << "Ingrese una opcion 1)Juego nuevo 2) solucion 3)salir :\n";
        cin >> opcion; // ingresa la opcion a elegir
        if(opcion==1){
            for(int i = 0; i < 4; i++){ // borra las variables de comparacion
                comp[i]=0;
                compPos[i]=0;
            }
            for(int i = 0; i < 4; i++){ // borra completamente el sudoku
                for(int j = 0; j < 4; j++){
                    sudoku[i][j] = 0;
                }
            }
            for(int i = 0; i < 4; i++){ // bucle que se repite 4 veces
                pos = rand() % 4 + 1; // genera un valor aleatorio para la posicion en y
                while(pos==compPos[0]||pos==compPos[1]||pos==compPos[2]||pos==compPos[3]){ // en caso de que el numero ya haya salido
                    pos = rand() % 4 + 1;
                }
                num = rand() % 4 + 1; // genera un numero aleatorio para la posicion anterior
                while(num==comp[0]||num==comp[1]||num==comp[2]||num==comp[3]){ // en caso de que el numero ya haya salido
                    num=rand() % 4 + 1;
                }
                comp[num-1] = num; // guarda el numero en el comparador de numeros
                compPos[pos-1] = pos; // guarda la posicion en el comparador de posicion
                base[0][i-1] = i-1;
                base[1][i-1] = num-1;// junto con la de arriba guarda las posiciones salidas previamente 
                sudoku[i][pos-1] = num; // guarda el valor en la posicion generada en el sudoku
            }
            // Aqui abajo imprime el sudoku junto con la cuadricula
            cout << "+---------------+\n";
            cout << "| " << sudoku[0][0] << " | " << sudoku[0][1] << " | " << sudoku[0][2] << " | " << sudoku[0][3] << " |\n";
            cout << "|---------------|\n";
            cout << "| " << sudoku[1][0] << " | " << sudoku[1][1] << " | " << sudoku[1][2] << " | " << sudoku[1][3] << " |\n";
            cout << "|---------------|\n";
            cout << "| " << sudoku[2][0] << " | " << sudoku[2][1] << " | " << sudoku[2][2] << " | " << sudoku[2][3] << " |\n";
            cout << "|---------------|\n";
            cout << "| " << sudoku[3][0] << " | " << sudoku[3][1] << " | " << sudoku[3][2] << " | " << sudoku[3][3] << " |\n";
            cout << "+---------------+\n\n";
        }
        else if(opcion==2){
            for(int i = 0; i < 4; i++){ 
                for(int p = 0; p < 4; p++){ // elimina todos los valores del comparador
                    comp[p]=0;
                }
                do{
                    for(int j = 0; j < 4; j++){ // recorre las 4 posiciones de la columna i
                        if((i!=base[0][0]||j!=base[1][0])&&(i!=base[0][1]||j!=base[1][1])&&(i!=base[0][2]||j!=base[1][2])&&(i!=base[0][3]||j!=base[1][3])){ // si en la casilla no hay un valor base
                            num=rand() % 4 + 1; // genera un numero aleatorio a guardar
                            while(num==comp[0]||num==comp[1]||num==comp[2]||num==comp[3]){ // en caso de que el numero ya esté en esa columna
                                num=rand() % 4 + 1;
                            }
                            sudoku[i][j]=num; // guarda el valor en el sudoku
                        }
                    }
                    for(int i = 0; i < 4; i++){
                        comp[i] = 0; // elimina los valores comparadores
                    }
                }while(revisarValidez()==false);
            }
            // de aqui para abajo imprime el sudoku con sus marcos
            cout << "+--------------+\n";
            cout << "| " << sudoku[0][0] << " | " << sudoku[0][1] << " | " << sudoku[0][2] << " | " << sudoku[0][3] << " |\n";
            cout << "|--------------|\n";
            cout << "| " << sudoku[1][0] << " | " << sudoku[1][1] << " | " << sudoku[1][2] << " | " << sudoku[1][3] << " |\n";
            cout << "|--------------|\n";
            cout << "| " << sudoku[2][0] << " | " << sudoku[2][1] << " | " << sudoku[2][2] << " | " << sudoku[2][3] << " |\n";
            cout << "|--------------|\n";
            cout << "| " << sudoku[3][0] << " | " << sudoku[3][1] << " | " << sudoku[3][2] << " | " << sudoku[3][3] << " |\n";
            cout << "+--------------+\n\n";
        }
        else if(opcion==3){
            break;
        }
        else{
            cout << "Opcion incorrecta, ingrese otra\n";
        }
    }

    return 0;
}


bool revisarValidez(){
    int pruebaDatos[4];
    bool valida = true;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){ // recorre la matriz
            pruebaDatos[j] = sudoku[i][j]; // guarda el valor de cada posicion de las columnas en pruebaDatos
        }
        for(int j = 0; j < 4; j++){
            for(int z = 0; z < 4; z++){
                if(pruebaDatos[j] == pruebaDatos[z] && j != z && pruebaDatos[i]!=0){ // revisa que los valores de cada columna no se repitan
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
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 4; i++){ // recorre la matriz
                pruebaDatos[i] = sudoku[i][j]; // guarda los valores de las filas
            }

            for(int i = 0; i < 4; i++){
                for(int z = 0; z < 4; z++){
                    if(pruebaDatos[i] == pruebaDatos[z] && i != z && pruebaDatos[i]!=0){ // compara que los valores en cada fila no se repitan
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
    return valida; // retorna si el sudoku es valido o no
}
