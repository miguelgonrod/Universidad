#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a, b, c, x1, x2;
    cout << "Ingresa el valor de a: \n";
    cin >> a;
    cout << "Ingresa el valor de b: \n";
    cin >> b;
    cout << "Ingresa el valor de c: \n";
    cin >> c;
    x1 = ((-1*b)+sqrt((b*b)-(4*a*c)))/(2*a);
    x2 = ((-1*b)-sqrt((b*b)-(4*a*c)))/(2*a);
    cout << "x1 es igual a: " << x1 << "\nx2 es igual a: " << x2;
    return 0;
}
