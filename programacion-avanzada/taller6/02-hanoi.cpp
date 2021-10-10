#include <iostream>
using namespace std;

/*
Nombre: hanoi
Objetivo: mover los discos a la posicion que es
Entradas:  discos, a, b, c
Salidas: void
*/
void hanoi(int discos, char a, char b, char c);

int main(){
    int discos;
    char a='a',b='b',c='c';
    cout << "Ingrese la cantidad de discos: ";
    cin >> discos;
    hanoi(discos,a,b,c);
    return 0;
}

void hanoi(int discos, char a, char b, char c){
    if(discos==1){
        cout << "Mueve el bloque " << discos << " desde " << a << " hacia " << b << endl;
    }
    else{
        hanoi(discos-1,a,c,b);
        cout << "Mueva el bloque " << discos << " desde " << a << " hacia " << b << endl;
        hanoi(discos-1,c,b,a);
    }
    return;
}
