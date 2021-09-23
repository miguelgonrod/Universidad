#include <iostream>
using namespace std;

void momentum(double velocidad[3], double masa);

int main(){
    double velocidad[3],masa;
    cout << "ingrese tres valores de la velocidad separados por un espacio:\n";
    cin >> velocidad[0] >> velocidad[1] >> velocidad[2];
    cout << "Ingrese la masa: \n";
    cin >> masa;
    momentum(velocidad, masa);
    return 0;
}

void momentum(double velocidad[3], double masa){
    double *ptr = new double[3];
    ptr[0]=velocidad[0]*masa;
    ptr[1]=velocidad[1]*masa;
    ptr[2]=velocidad[2]*masa;
    cout << "Momentum 1: " << ptr[0] << "\nMomentum 2: " << ptr[1] << "\nMomentum 3: " << ptr[2];
    delete[] ptr;
    return;
}
