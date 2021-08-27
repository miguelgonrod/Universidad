// Programa que lee un año y muestra si es o no bisiesto
#include <iostream>
using namespace std;

int bisiesto(int a);   //declaración o prototipo de la función

int main()
{
   int anio;
   int *pointanio=&anio;
   cout<<"Introduce a" << char(164) << "o: "; //164 ascii de ñ
   cin >> *pointanio;
   if(bisiesto(*pointanio))  //llamada a la función
      cout << "Bisiesto" << endl;
   else
      cout << "No es bisiesto" << endl;
   system("pause"); 
}

int bisiesto(int a)   //definición de la función    
{
    if(a%4==0 and a%100!=0 or a%400==0)
        return 1;
    else
        return 0;
}
