#include <iostream>
#include <string.h>
using namespace std;


/*
Nombre: palabras
Objetivo: ir reduciendo en uno el tamaño de la palabra e imprimirla
Entradas:  palabra[100], longitud
Salidas: void
*/

void palabras(char palabra[100], int longitud);

int main(){
    string pal;
    char palabra[100];
    int longitud;
    cout << "Ingrese una palabra:\n";
    getline(cin>>ws,pal);
    strcpy(palabra,pal.c_str());
    longitud = strlen(palabra);
    palabras(palabra, longitud);
    return 0;
}

void palabras(char palabra[100], int longitud){
    int lon = (strlen(palabra))-longitud;
    for(int i = lon; i<strlen(palabra); i++){
        cout << palabra[i];
    }
    cout << endl;
    if(longitud >= 1){
        palabras(palabra, longitud-1);
    }
    else{
        return;
    }
}
