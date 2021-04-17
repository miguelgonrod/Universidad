#include <iostream>
using namespace std;

void desencriptar(int val);

int main(){
    int m, n;
    cout << "ingresa las dimensiones de la matriz m*n (ejm: 4 5)\n";
    cin >> m >> n;
    int matriz[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Ingrese el valor m[" << i+1 << "] n[" << j+1 << "]\n";
            cin >> matriz[i][j];
        }
    }
    int cont = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int val = matriz[i][j];
            cout << cont;
            desencriptar(val);
            cont++;
        }
    }
    return 0;
}

void desencriptar(int val){
    switch(val){
        case 1:
            cout << "a";
            break;
        case 2:
            cout << "b";
            break;
        case 3:
            cout << "c";
            break;
        case 4:
            cout << "d";
            break;
        case 5:
            cout << "e";
            break;
        case 6:
            cout << "f";
            break;
        case 7:
            cout << "g";
            break;
        case 8:
            cout << "h";
            break;
        case 9:
            cout << "i";
            break;
        case 10:
            cout << "j";
            break;
        case 11:
            cout << "k";
            break;
        case 12:
            cout << "l";
            break;
        case 13:
            cout << "m";
            break;
        case 14:
            cout << "n";
            break;
        case 15:
            cout << "o";
            break;
        case 16:
            cout << "p";
            break;
        case 17:
            cout << "q";
            break;
        case 18:
            cout << "r";
            break;
        case 19:
            cout << "s";
            break;
        case 20:
            cout << "t";
            break;
        case 21:
            cout << "u";
            break;
        case 22:
            cout << "v";
            break;
        case 23:
            cout << "w";
            break;
        case 24:
            cout << "x";
            break;
        case 25:
            cout << "y";
            break;
        case 26:
            cout << "z";
            break;
        case 27:
            cout << " ";
            break;

    }
    return;
}
