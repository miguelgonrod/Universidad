#include <iostream>
using namespace std;
int main(){
    const float hormiguero = 7000.0;
    const float tasaNormal = 1.4;
    const float tasaAlterada = 1.315;
    float hormigas;
    int meses;
    int contador = 0;
    cout << "Ingresa el numero de hormigas iniciales: ";
    cin >> hormigas;
    cout << "Ingrese el numero de meses a calcular: ";
    cin >> meses;
    while(contador < meses){
        if(hormigas > 28000){
            hormigas = hormigas * tasaAlterada;
        }
        else{
            hormigas = hormigas * tasaNormal;
        }
        if(hormigas <= hormiguero){
            cout << "El oso hormiguero se ha comido todas las hormigas";
            return 0;
        }
        else{
            hormigas -= hormiguero;
        }
        contador++;
    }
    cout << "la cantidad de hormigas en el mes " << meses << " es de " << hormigas;
    return 0;
}
