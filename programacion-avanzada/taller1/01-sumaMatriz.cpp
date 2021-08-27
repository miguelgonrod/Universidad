02-posiciones.cpp                                                                                   0000644 0001750 0001750 00000001345 14101125372 013501  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
using namespace std;
int main(){
    int numeros[10]={0,0,0,0,0,0,0,0,0,0}, num, pos;
    while(true){
        cout << "Ingrese un numero: ";
        cin >> num; // pregunta el numero a guardar
        cout << "Ingrese una posicion entre 1 y 10 (un negativo cierra el programa)\n";
        cin >> pos; // pregunta la posicion a guardar o en su defecto si quiere acabar el codigo
        if(pos < 0){
            break; // cierra el ciclo para acabar el codigo
        }
        else{
            numeros[pos-1] = num; // guarda el valor ingresado en la posicion ingresada
        }
    }
    for(int i = 0; i < 10; i++){
        cout << numeros[i] << " "; // imprime los valores dentro de el vector
    }
    return 0;
}
                                                                                                                                                                                                                                                                                           03-vectorRandom.cpp                                                                                 0000644 0001750 0001750 00000001415 14101125613 013766  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int nums[100], pos;
    for(int i = 0; i < 100; i++){ // genera un numero aleatorio entre 1 y 1000000 diferente para cada uno de los 100 valores del vector
        nums[i]=rand() % 1000000 + 1;
    }
    while(true){
        cout << "Ingresa la posicion a la cual quieres revisar el numero 1-100 (valor negativo acaba el programa):\n";
        cin >> pos; // pregunta la posicion a la cual quiere ver el valor o en su defecto acaba el programa
        if(pos < 0){
            break;
        }
        else if(pos <= 100){
            cout << nums[pos-1] << endl; // imprime el valor
        }
        else{
            cout << "posicion invalida\n";
        }
    }
    return 0;
}
                                                                                                                                                                                                                                                   04-menu.cpp                                                                                         0000644 0001750 0001750 00000002162 14101126041 012264  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
#include <ctime>
using namespace std;

void delay(int secs);

int main(){
    int opcion;
    while(true){
        cout << "Ingrese una opcion 1)insertar 2)borrar 3)imprimir 4)salir: ";
        cin >> opcion; // pregunta la opcion a elegir
        switch(opcion){
            case 1:
                cout << "ahorita te inserto el valor\n";
                delay(3); // espera 3 secs, igual con todos los delay
                break;
            case 2:
                cout << "Ahorita te borro el valor\n";
                delay(3);
                break;
            case 3:
                cout << "Ahorita te imprimo el valor\n";
                delay(3);
                break;
            case 4:
                break;
            default:
                cout << "opcion invalida\n";
                break;
        }
        if(opcion == 4){
            break; // termina el codigo
        }
    }
    return 0;
}

void delay(int secs){ // esta funcion aprovecha un bucle for y el valor de la funcion time para generar un delay
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
    return;
}
                                                                                                                                                                                                                                                                                                                                                                                                              05-menuVector.cpp                                                                                   0000644 0001750 0001750 00000004130 14101126340 013447  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
using namespace std;
int main(){
    int opcion, pos, sus, nums[10]={0,0,0,0,0,0,0,0,0,0};
    while(true){
        cout << "Ingrese una opcion 1)Insertar 2)borrar 3)Imprimir 4)salir:\n";
        cin >> opcion; // pregunta la opcion a elegir
        switch(opcion){
            case 1:
                cout << "Ingrese la posicion a la cual quiere insertar el valor: ";
                cin >> pos; // pregunta la posicion donde se va a guardar el valor
                while(pos < 1 || pos > 10){ // en caso de una posicion invalida
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "ingrese el numero a colocar: ";
                cin >> sus; // ingresa el valor a guardar
                nums[pos-1] = sus; // guarda el valor en la posicion ingresada
                cout << "valor insertado correctamente\n\n";
                break;
            case 2:
                cout << "Ingrese la posicion de la cual quiere borrar el valor:\n";
                cin >> pos; // pregunta la posicion del valor a borrar
                while(pos < 1 || pos > 10){
                    cout << "Opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                nums[pos-1] = 0; // borra el valor volviendolo 0
                cout << "Valor borrado correctamente\n\n";
                break;
            case 3:
                cout << "Ingrese la posicion de la cual quiere mostrar el valor:\n";
                cin >> pos; // pregunta la posicion del valor a mostrar
                while(pos < 1 || pos > 10 ){
                    cout << "opcion invalida, ingrese de nuevo\n";
                    cin >> pos;
                }
                cout << "valor: " << nums[pos-1] << "\n\n"; // imprime el valor
                break;
            case 4:
                break;
            default:
                cout << "opcion invalida, ingrese otra de nuevo\n";
                break;
        }
        if(opcion == 4){ // cierra el programa
            break;
        }
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                        06-menuCompleto.cpp                                                                                 0000644 0001750 0001750 00000005331 14101126621 013776  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
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
                                                                                                                                                                                                                                                                                                       07-matrizRandom.cpp                                                                                 0000644 0001750 0001750 00000001251 14101126773 014004  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL)); // selecciona la semilla del random la cual va a ser el tiempo de nuestro reloj
    int nums[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){ // entre estos dos for recorremos toda la matriz 100 x 100 para guardar un valor
            nums[i][j] = rand() % 1000 + 1; // genera un valor aleatorio entre 1 y 1000
        }
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            cout << nums[i][j] << "  "; // junto con los for imprime todos los valores de la matriz
        }
        cout << "\n";
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                       08-matrizCompleta.cpp                                                                               0000644 0001750 0001750 00000001730 14101127221 014320  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int nums[100][100], min, max;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            nums[i][j] = rand() % 1000 + 1; // recorre toda la matriz ingresando valores aleatorios entre 1 y 1000
            if(i == 0 && j == 0){ // en caso de ser el primer valor tomar como valor inicial para el minimo y el maximo
                min = nums[i][j];
                max = nums[i][j];
            }
            if(nums[i][j] > max){ // en caso de que el nuevo valor sea mayor que en el anterior sustituir el valor mayor
                max = nums[i][j];
            }
            if(nums[i][j] < min){ // en caso de que el nuevo valor sea menor que en el anterior sustituir el valor menor
                min = nums[i][j];
            }
        }
    }
    cout << "Minimo: " << min << "\nMaximo: " << max; // imprime el valor mayor y el valor menor
    return 0;
}
                                        09-traspuesta.cpp                                                                                   0000644 0001750 0001750 00000001251 14101127345 013526  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
using namespace std;
int main(){
    int matriz[3][3], num;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){ // recorre toda la matriz
            cout << "Ingrese el valor de x: " << j+1 << " y: " << i+1 << ":\n";
            cin >> num; // ingresa un valor para la posicion determinada por i y j
            matriz[i][j] = num; // guarda el valor
        }
    }
    cout << "\n\nTraspuesta\n\n";
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++){ // recorre la matriz en vertical para generar la traspuesta
            cout << matriz[i][j] << " "; // imprime el valor
        }
        cout << endl;
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                       10-matrizMenu.cpp                                                                                   0000644 0001750 0001750 00000005516 14101130427 013461  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
using namespace std;

void OrdenamientoAs(int arreglo[]);
void OrdenamientoDes(int arreglo[]);

int main(){
    int opcion, vec[7]={0,0,0,0,0,0,0}, num;
    while(true){
        cout << "Ingresa la opcion 1)Ingresar datos 2)Ordenar-ascendente 3)Ordenar-descendente 4)Imprimir 5)salir :\n";
        cin >> opcion; // ingresa la opcion a elegir
        switch(opcion){
            case 1:
                for(int i = 0; i < 7; i++){ // recorre todo el vector preguntando que valor ingresar
                    cout << "Ingrese el valor de la posicion " << i+1 << ": ";
                    cin >> num; // pregunta el valor
                    vec[i]=num; // almacena el valor
                }
                cout << "valores ingresados correctamente\n\n";
                break;
            case 2:
                OrdenamientoAs(vec); // llama a la funcion de ordenar ascendente
                cout << "Valores ordenados correctamente\n\n";
                break;
            case 3:
                OrdenamientoDes(vec); // llama a la funcion de ordenar descendente
                cout << "Valores ordenados correctamente\n\n";
                break;
            case 4:
                for(int i = 0; i < 7; i++){ // recorre todo el vector imprimiendo cada uno de sus valores
                    cout << vec[i] << "  ";
                }
                cout << "\n\n";
                break;
            case 5:
                break;
            default:
                cout << "Opcion incorrecta, ingrese otra nuevamente\n";
                break;
        }
        if(opcion==5){
            break;
        }
    }
    return 0;
}

void OrdenamientoAs(int arreglo[]){
    int aux;
    for(int i = 0; i < 7; i++){ // recorre el vector
        for(int j = 0; j < 7-1-i; j++){ // recorre el vector de abajo hacia arriba desde el valor de la posicion i
            if(arreglo[j] > arreglo[j+1]){ // si el valor actual es mayor al valor siguiente
                aux = arreglo[j]; // guarda el valor actual en aux
                arreglo[j] = arreglo[j+1]; // guarda el valor siguiente en la posicion actual
                arreglo[j+1] = aux; // guarda el valor de aux en la proxima posicion
            }
        }
    }
    return;
}

void OrdenamientoDes(int arreglo[]){
    int aux;
    for(int i = 0; i < 7; i++){ // recorre todo el vector
        for(int j = 0; j < 7-1-i; j++){ // recorre el vector de abajo hacia arriba desde el valor de la posicion i
            if(arreglo[j] < arreglo[j+1]){ // si el valor actual es menor al valor siguiente
                aux = arreglo[j]; // guarda el valor actual en la variable aux
                arreglo[j] = arreglo[j+1]; // guarda el valor siguiente en la posicion actual
                arreglo[j+1] = aux; // guarda en la posicion siguiente el valor en la variable aux
            }
        }
    }
    return;
}
                                                                                                                                                                                  11-sudoku.cpp                                                                                       0000644 0001750 0001750 00000013773 14101141725 012650  0                                                                                                    ustar   miguel                          miguel                                                                                                                                                                                                                 #include <iostream>
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     