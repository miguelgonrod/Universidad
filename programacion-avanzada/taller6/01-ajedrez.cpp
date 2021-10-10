#include <iostream>
#include <math.h>
using namespace std;

/*
Nombre: potencia
Objetivo: ejecutarse a si misma la misma cantidad de veces que cuadros tiene un tablero de ajedrez elevando a la n potencia su denominacion numerica para saber cuanto maiz se necesita
Entradas:  pot y num
Salidas: long double
*/
long double potencia(int pot, int num);

int main(){
    int num = 2, pot = 63;
    cout << "El resultado es: " << potencia(pot, num);
    return 0;
}

long double potencia(int pot, int num){
    if(pot<0){
        return 0;
    }
    else{
        return pow(2,pot) + potencia(pot-1, num);
    }
}
