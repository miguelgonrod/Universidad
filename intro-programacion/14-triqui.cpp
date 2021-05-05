#include <iostream>
#include <string>
using namespace std;

void mapa(char casillas[3][3]);
int turno(int jugador);

int main(){
    int jugador = 1;
    char casillas[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            casillas[i][j] = ' ';
        }
    }

    while(!((casillas[0][0]==casillas[0][1]&&casillas[0][1]==casillas[0][2] &&casillas[0][0]!=' ') || (casillas[1][0]==casillas[1][1]&&casillas[1][1]==casillas[1][2]&&casillas[1][0]!=' ') || (casillas[2][0]==casillas[2][1]&&casillas[2][1]==casillas[2][2]&&casillas[2][0]!=' ') || (casillas[0][0]==casillas[1][0]&&casillas[1][0]==casillas[2][0]&&casillas[0][0]!=' ') || (casillas[1][0]==casillas[1][1]&&casillas[1][1]==casillas[1][2]&&casillas[1][0]!=' ') || (casillas[2][0]==casillas[2][1]&&casillas[2][1]==casillas[2][2]&&casillas[2][0]!=' ') || (casillas[0][0]==casillas[1][1]&&casillas[1][1]==casillas[2][2]&&casillas[0][0]!=' ') || (casillas[2][0]==casillas[1][1]&&casillas[1][1]==casillas[0][2]&&casillas[2][0]!=' '))){
        turno(jugador);
        if(jugador==1){
            jugador++;
        }
        else{
            jugador--;
        }
    }
    if(jugador == 1){
        jugador++;
    }
    else{
        jugador--;
    }
    cout << "El jugador " << jugador << " ha ganado";
    return 0;
}

void mapa(char casillas[3][3]){
    cout << casillas[0][0] << "|" << casillas[0][1] << "|" << casillas[0][2] << endl;
    cout << "-*-*-" << endl;
    cout << casillas[1][0] << "|" << casillas[1][1] << "|" << casillas[1][2] << endl;
    cout << "-*-*-" << endl;
    cout << casillas[2][0] << "|" << casillas[2][1] << "|" << casillas[2][2] << endl;
    return;
}

int turno(int jugador){
    char letra;
    int posicion;
    if(jugador == 1){
        letra = 'X';
    }
    else{
        letra = 'O';
    }
    cout << "Jugador " << jugador << " en que casilla desea poner" << letra << "?: ";
    cin >> posicion;
    while(posicion < 1 || posicion > 9){
        cout << "Valores del 1 al 9: ";
        cin >> posicion;
    }
    return posicion;
}
