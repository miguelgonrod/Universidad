#include <iostream>
using namespace std;
int main(){
    int tam1, tam2;
    int *cantLetr = new int;
    *cantLetr=0;
    int *i = new int;
    *i=0;
    int *prom = new int;
    *prom=0;
    int *buf = new int;
    *buf=1;
    char *letr = new char[1];
    cout << "Ingrese el tamaño de el primer y segundo buffer separados por un espacio:\n";
    cin >> tam1 >> tam2;
    while(tam1 < 1 || tam2 < 1){
        cout << "Ingrese tamaños validos mayores a 1:\n";
        cin >>tam1 >> tam2;
    }
    int *buffer1 = new int[tam1];
    int *buffer2 = new int[tam2];
    cout << "Ingrese caracter por caracter, en caso de querer salir ingrese un caracter especial:\n";
    while(true){
        cin >> letr;
        if((int)*letr < 65 || ((int)*letr > 90 && (int)*letr < 97) || (int)*letr > 122){
            break;
        }
        else if(*i < tam1 && *buf==1){
            buffer1[*i]= (int)*letr;
            *cantLetr+=1;
            *prom+=buffer1[*i];
            *i+=1;
        }
        else if(*i < tam2 && *buf==2){
            buffer2[*i-tam1] = (int)*letr;
            *cantLetr+=1;
            *prom+=buffer2[*i];
            *i+=1;
        }
        if(*i==tam1 && *buf==1){
            cout << "El primer buffer se llenó\n";
            *buf=2;
            *i=0;
            *prom=*prom /  *cantLetr;
            cout << "Promedio: " << *prom << endl;
            *prom=0;
            *cantLetr=0;
            delete[] buffer1;
            int *buffer1 = new int[tam1];
        }
        if(*i==tam2 && *buf==2){
            cout << "El segundo buffer se llenó\n";
            *buf=1;
            *i=0;
            *prom=*prom / *cantLetr;
            cout << "Promedio: " << *prom << endl;
            *prom=0;
            *cantLetr=0;
            delete[] buffer2;
            int *buffer2 = new int[tam2];
        }
    }
    return 0;
}
