#include <iostream>
#include <math.h>
using namespace std;

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