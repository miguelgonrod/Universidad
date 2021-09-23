#include <iostream>
using namespace std;

int bisiesto(int a);

int main(){
    int anio;
    int *pointanio=&anio;
    cout <<"introduce a"<<(char)164<<"o: ";
    cin >> *pointanio;
    if(bisiesto(*pointanio))
        cout << "Bisiesto" << endl;
    else
        cout << "No es bisiesto" << endl;
    system("pause");
    return 0;
}

int bisiesto(int a){
    if(a%4==0 and a%100!=0 or a%400==0)
        return 1;
    else
        return 0;
}
