#include <iostream>
using namespace std;
int main()
{
    float farenheit, celcius;
    cout << "Ingresa los grados farenheit: \n";
    cin >> farenheit;
    celcius = (farenheit-32)*(5/9);
    cout << farenheit << " grados farenheit son " << celcius << " grados centigrados";
    return 0;
}
