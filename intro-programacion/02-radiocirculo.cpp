#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float radio, perimetro, area;
    cout << "Digite el radio del circulo: \n";
    cin >> radio;
    perimetro = 2*M_PI*radio;
    area = M_PI*pow(radio,2);
    cout << "El perimetro de la circunferencia es: " << perimetro << "\n";
    cout << "El area de la circunferencia es: " << area;
    return 0;
}
