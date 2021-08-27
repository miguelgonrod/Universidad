#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void imprimirTablero();
void delay(int secs);

char tablero[20][20];

int main(){
    int x1,y1,x2,y2,turnos=0,posAct[2];
    for(int i = 0; i < 20; i++){ // borra el tablero
        for(int j = 0; j < 20; j++){
            tablero[i][j]=' ';
        }
    }
    cout << "Ingrese un punto (x y) separados por un espacio (entre 0 y 19): ";
    cin >> x1 >> y1;
    while(x1 < 0 || y1 < 0 || x1>19 || y1 >19){
        cout << "Ingrese un punto valido\n";
        cin >> x1 >> y1;
    }
    cout << "Ingrese el segundo punto bajo las mismas condiciones: ";
    cin >> x2 >> y2;
    while(x2<0||x2>19||y2<0||y2>19){
        cout << "Ingrese un punto valido\n";
        cin >> x2 >> y2;
    }
    while(x1==x2 && y1==y2){
        cout << "Porque quieres unir el mismo punto? ingresa otro nuevo\n";
        cin >> x2 >> y2;
    }
    tablero[y1][x1]='*'; // marca la posicion inicial en el tablero
    tablero[y2][x2]='*'; // marca la posicion final en el tablero
    posAct[0]=x1; // guardamos la posicion inicial en un marcador
    posAct[1]=y1;
    system("clear"); // borra la terminal ( en caso de estar en windows cambiar por cls )
    turnos=abs(x1-x2)+abs(y2-y1); // calculamos cuantos movimientos se necesitaran
    for(int i=0; i < turnos; i++){
        imprimirTablero(); // llama a la funcion que imprime el tablero
        if(posAct[0]<x2){ // en este if y el else if de abajo revisamos si la posicion final esta mas abajo o arriba
            posAct[0]++;
        }
        else if(posAct[0]>x2){
            posAct[0]--;
        }
        else{
            if(posAct[1]<y2){ // este if y el else de abajo revisa si la posicion final está a la izquierda o a la derecha
                posAct[1]++;
            }
            else{
                posAct[1]--;
            }
        }
        tablero[posAct[1]][posAct[0]]='*'; // marcamos la posicion actual con *
        delay(1); // delay de 1 seg
        system("clear"); // en caso de estar en windows cambiar por cls
    }
    imprimirTablero();
    return 0;
}

void imprimirTablero(){ // funcion que imprime el tablero
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            cout << tablero[i][j];
        }
        cout << endl;
    }
    return;
}

void delay(int secs){ // usando un for y la libreria time crean un delay en segundo // usando un for y la libreria time crean un delay en segundos
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
