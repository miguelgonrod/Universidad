#include <iostream>

using namespace std;

void divisionSucesivaDe(int dividendo, int divisor);

int main()
{
    int dividendo, divisor;
    int *apuntadordendo = &dividendo, *apuntadorsor=&divisor;
    cout << "Ingrese el dividendo: "; cin>>*apuntadordendo;
    cout << "Ingrese el divisor: "; cin>>*apuntadorsor;
    divisionSucesivaDe(*apuntadordendo,*apuntadorsor);

    return 0;
}

void divisionSucesivaDe(int dividendo, int divisor){
    int cociente=0;
    int *apuntcociente=&cociente;
    while(dividendo >= divisor)
    {
	dividendo -= divisor; cociente++; 
    }
    cout<<"El resto es: "<<dividendo<<endl;
    cout<<"El cociente es: "<<*apuntcociente<<endl;
    return;
}
