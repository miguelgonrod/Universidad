#include <iostream>
#include <string>
using namespace std;

int dificultad();
string dibujarTablero(string tablero);

int main(){
    int nivel = dificultad();
    string tablero[19][19]={{"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},
                           {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "},
                           {"+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"," ","+"},};
    int lineas
    if(nivel == 1){}
    else if(nivel == 2){}
    else{}
}

int dificultad(){
    int nivel=0;
    cout << "Bienvenido a cuadrito\n";
    while(nivel < 1 || nivel > 3){
        cout << "Que nivel de dificultad quiere? 1)facil 2)medio 3)dificil\n";
        cin >> dificultad;
    }
    return nivel;
}

string dibujarTablero(string tablero){
    cout << "+" << tablero[0] << "+" << tablero[1] << "+" << tablero2 [2]<< "+" << tablero[3] << "+" << tablero[4] << "+" << tablero[5] << "+" << tablero[6] << "+" << tablero[7] << "+" << tablero[8] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
    cout << tablero[9] << " " << tablero[10] << " " << tablero[11] << " " << tablero[12] << " " << tablero[13] << " " << tablero[14] << " " << tablero[15] << " " << tablero[16] << " " << tablero[17] << " " << tablero[18];
    cout << "+" << tablero[19] << "+" << tablero[20] << "+" << tablero2 [21]<< "+" << tablero[22] << "+" << tablero[23] << "+" << tablero[24] << "+" << tablero[25] << "+" << tablero[26] << "+" << tablero[27] << "+";
}