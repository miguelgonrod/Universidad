#include <iostream>
using namespace std;
int main(){
    int numero, caracter1, caracter2, caracter3, caracter4, suma=0, numFinal; // inicializo variables
    string otraVez="si";
    while(otraVez == "si" || otraVez == "Si"){ // hasta que no digan que no quieren correr esto otra vez esto va a ser infinito
        while(numero > 9999 || numero < 1000){ // reviso si el numero es mayor a 9999 o menor a 1000
           cout << "\nIngrese un numero de 4 cifras: "; // si eso ocurre tiene que ingresar un numero valido
           cin >> numero;
        }
        caracter1 = numero % 10; // saco el ultimo digito y lo almaceno
        numero = numero/10; // remuevo el ultimo digito
        caracter2 = (numero % 10); // se aquí hasta el caracter 4 es el mismo proceso
        numero = numero/10;
        caracter3 = (numero % 10);
        numero = numero / 10;
        caracter4 = (numero % 10);
        suma = caracter1 + caracter2 + caracter3 + caracter4; // sumo los digitos
        numFinal= caracter1 + caracter2 * 10 + caracter3 * 100 + caracter4 * 1000; // vuelvo a crear el numero original pero en la variable numFinal
        if(suma % 2 == 0){ // reviso si la suma de los digitos es par
            numFinal = numFinal * 10 + 1; // si es par a numFinal le agregro el 1 al final multiplicandolo por 10 y sumandole 1
        }
        else{ // reviso si es impar
            numFinal = numFinal * 10; // lo mismo del par pero sin sumar 1 por lo tanto se le agrega un 0
        }
        cout << "El numero de la tarjeta seria: " << numFinal;
        cout << "\nDeseas probar otro numero?: (si/no) ";
        cin >> otraVez; // reviso si quiere hacer esto otra vez o no
    }
    return 0;
}
