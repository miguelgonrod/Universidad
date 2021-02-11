#include <iostream>
using namespace std;
int main()
{
    string name, fatherName, motherName;
    cout << "Escribe el nombre de tu padre: \n";
    cin >> fatherName;
    cout << "Escribe el nombre de tu madre: \n";
    cin >> motherName;
    cout << "Escribe tu nombre: \n";
    cin >> name;
    cout << "“La/El hija/o de " << fatherName << " y " << motherName << " es " << name;
    return 0;
}
