#include <iostream>
using namespace std;
int main()
{
    float B, b, h, area;
    cout << "Ingresa la base mayor (B): \n";
    cin >> B;
    cout << "Ingresa la base menor (b): \n";
    cin >> b;
    cout << "Ingresa la altura (h): \n";
    cin >> h;
    area = ((B+b)*h)/2;
    cout << "El area de tu trapecio es: " << area;
    return 0;
}
