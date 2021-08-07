#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

char movimiento();
void delay(int secs);

int posx, posy;

int main(){
    srand(time(NULL));
    ofstream Destino;
    ifstream Leer;
    int pasos, opcion, direccion, guardar;
    int inicio[2], fin[2];
    char mapa[100][100];
    while(true){
        cout << "Quiere 1)Nueva-ruta 2)ver-guardada 3)salir: \n";
        cin >> opcion;
        if(opcion==1){
            for(int i = 0; i < 100; i++){
                for(int j = 0; j < 100; j++){ // estos dos for recorren toda la matriz limpiandola
                    mapa[i][j] = ' ';
                }
            }
            cout << "Ingrese el numero de pasos del robot (1-200): ";
            cin >> pasos;
            while(pasos < 1 || pasos > 200){
                cout << "Cantidad de pasos incorrecta, ingrese otra nuevamente\n";
                cin >> pasos;
            }
            posx = rand() % 99; // crea una posicion inicial en x aleatoria
            posy = rand() % 99; // crea una posicion inicial en y aleatoria
            inicio[0]= posy;
            inicio[1]= posx; // entra ambas guarda el valor inicial
            system("clear"); // limpia la terminal
            for(int i = 0; i < pasos; i++){
                mapa[inicio[0]][inicio[1]] = 'I'; // pone en la posicion inicial una I
                if(i == pasos-1){ // pone en la posicion final una F
                    mapa[posy][posx] = 'F';
                    fin[0] = posy;
                    fin[1] = posx;
                }
                delay(1); // llama a la funcion propia delay
                system("clear");
                for(int j = 0; j < 100; j++){
                    for(int p = 0; p < 100; p++){ // entre estos dos for recorren toda la matriz imprimiendola
                        cout << mapa[j][p];
                    }
                    cout << endl;
                }
                mapa[posy][posx] = movimiento(); // llama a la funcion propia movimiento para generar un movimiento aleatorio
            }
            mapa[fin[0]][fin[1]] = 'F';
            cout << "Desea guardar estos movimientos?: 1)si 2)no\n";
            cin >> guardar;
            while(guardar < 1 || guardar > 2){
                cout << "Opcion invalida, ingrese una nuevamente\n";
                cin >> guardar;
            }
            if(guardar==1){ // en caso de quererlo guarda los movimientos
                Destino.open("Guardado.txt", ios::binary); // abre el archivo guardado.txt en modo escritura binaria
                Destino.write((char *)&mapa,sizeof(mapa)); // escribe el valor de la matriz mapa en el archivo
                cout << "Partida guardada correctamente\n\n";
                Destino.close(); // cierra el archivo
            }
            else{
                cout << "La partida no se ha guardado\n\n";
            }
        }
        else if(opcion==2){
            system("clear"); // limpia la terminal
            Leer.open("Guardado.txt");  // abre el archivo guardado.txt en modo lectura
            Leer.read((char *)&mapa,sizeof(mapa)); // lee el mapa guardado previamente
            for(int i = 0; i < 100; i++){
                for(int j = 0; j < 100; j++){ // imprime todo el mapa guardado
                    cout << mapa[i][j];
                }
                cout << endl;
            }
            Leer.close(); // cierra el archivo
            cout << "\n\n";
        }
        else if(opcion==3){
            break;
        }
        else{
            cout << "Opcion incorrecta, ingrese otra\n\n";
        }
    }
    return 0;
}

char movimiento(){ // funcion propia que genera un movimiento aleatorio
    char caracter;
    int direccion, pasado = 0;
    pasado = 0;
    while(true){
        direccion = rand() % 4 + 1; // genera un numero aleatorio entre 1 y 4 que eligue a donde se va a mover
        if(direccion==1){
            if(posx-1 < 0){ // revisa que no se salga del mapa
                pasado = 1;
            }
            else{
                posx-=1;
                caracter = '<'; // movimiento a la izquierda
            }
        }
        else if(direccion==2){
            if(posx+1 > 99){ // revisa que no se salga del mapa
                pasado = 1;
            }
            else{
                posx+=1;
                caracter = '>'; // movimiento a la derecha
            }
        }
        else if(direccion==3){
            if(posy-1 < 0){ // revisa que no se salga del mapa
                pasado = 1;
            }
            else{
                posy-=1;
                caracter = '^'; // movimiento arriba
            }
        }
        else if(direccion==4){
            if(posy+1 > 99){ // revisa que no se salga del mapa
                pasado = 1;
            }
            else{
                posy+=1;
                caracter = 'v'; // movimiento hacia abajo
            }
        }
        if(pasado==0){
            break;
        }
    }
    return caracter;
}

void delay(int secs){ // funcion propia que genera un delay en segundos
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
