#include <iostream>
using namespace std;
int main(){
    int conejosMañana,conejosHoy,conejosAyer,dias = 0;
    cout << "Ingrese la cantidad de conejos ayer: ";
    cin >> conejosAyer;
    cout << "Ingrese la cantidad de conejos hoy: ";
    cin >> conejosHoy;
    while(conejosMañana <= 70000){
        conejosMañana = conejosHoy + conejosAyer;
        conejosAyer = conejosHoy;
        conejosHoy = conejosMañana;
        dias++;
    }
    cout << "En " << dias << " dias la poblacion de conejos va a sobrepasar los 70000";

}
