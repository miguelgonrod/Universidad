#include <iostream>
using namespace std;

int verificar[100][100];
int validas[100][100];
int n, m, cantidad;

void ingresarDatos();
void verificarValidas();
void imprimir();

int main(){
    ingresarDatos();
    verificarValidas();
    imprimir();
    return 0;
}

void ingresarDatos(){
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> n;
    while(n < 1 || n > 100){
        cout << "Ingrese un numero valido entre 1 y 100: ";
        cin >> n;
    }
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> m;
    while(m < 1 || m > 100){
        cout << "Ingrese un numero valido entre 1 y 100: ";
        cin >> m;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Ingrese el valor de [" << i << "," << j << "]: ";
            cin >> verificar[j][i];
        }
    }
    return;
}

void verificarValidas(){
    int suma;
    cantidad = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            suma = 0;
            if(j-1 >= 0){
                suma += verificar[j-1][i];
                if(i+1 != m){
                    suma += verificar[j-1][i+1];
                }
                if(i-1 >= 0){
                    suma+= verificar[j-1][i-1];
                }
            }

            if(j+1 != n){
                suma += verificar[j+1][i];
                if(i+1 != m){
                    suma += verificar[j+1][i+1];
                }
                if(i-1 >= 0){
                    suma += verificar[j+1][i-1];
                }
            }
            if(i-1 >= 100){
                suma += verificar[j][i-1];
            }
            if(i+1 != m){
                suma += verificar[j][i+1];
            }
            if(suma == verificar[j][i]){
                validas[0][cantidad] = verificar[j][i];
                validas[1][cantidad] = i;
                validas[2][cantidad] = j;
                cantidad++;
            }
        }
    }
    return;
}

void imprimir(){
    cout << "Numero fila Columna\n";
    for(int i = 0; i < cantidad; i++){
        cout << validas[0][i] << "      " << validas[1][i] << "    " << validas[2][i] << endl;
    }
    return;
}
