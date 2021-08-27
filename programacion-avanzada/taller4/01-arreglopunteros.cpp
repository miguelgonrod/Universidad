#include <iostream>
using namespace std;

void opcion1();
void opcion2();
void opcion3();
void opcion4();
void opcion5();
void opcion6();

int arreglo[15], *puntarreglo[15], tabla, inicio,paso1=0,paso2=0;

int main(){
    int opcion;
    do{
        cout << "Desea \n1)Crear tabla de multiplicar\n2)Almacenar posiciones\n3)Mostrar valores y direcciones\n4)intercambiar direcciones de memoria\n5)Ordenar direcciones ascendentes\n6)Ordenar direcciones descedentes\n7)salir\n";
        cin >> opcion;
        while(opcion<1||opcion>7){
            cout << "Ingrese una opcion valida\n";
            cin >> opcion;
        }
        switch(opcion){
            case 1:
                opcion1();
                break;
            case 2:
                if(paso1==0){
                    cout<< "Primero usa la opcion 1\n";
                }
                else{
                    opcion2();
                }
                break;
            case 3:
                if(paso2==0){
                    cout<< "Primero usa la opcion 2\n";
                }
                else{
                    opcion3();
                }
                break;
            case 4:
                if(paso2==0){
                    cout<< "Primero usa la opcion 2\n";
                }
                else{
                    opcion4();
                }
                break;
            case 5:
                if(paso2==0){
                    cout<< "Primero usa la opcion 2\n";
                }
                else{
                    opcion5();
                }
                break;
            case 6:
                if(paso2==0){
                    cout<< "Primero usa la opcion 2\n";
                }
                else{
                    opcion6();
                }
                break;
        }
    }while(opcion!=7);
    return 0;
}

void opcion1(){ // crea la tabla
    cout << "\nIngrese el numero el cual va a generar su tabla: ";
    cin >> tabla;
    cout << "Ingrese el numero de inicio a multiplicar: ";
    cin >> inicio;
    for(int i = 0; i < 15; i++){ // hace un ciclo for para hacer la tabla
        arreglo[i]=tabla*(inicio+i);
        cout << arreglo[i] << endl;
    }
    paso1=1;
    cout << endl;
    return;
}

void opcion2(){ // guarda las posiciones
    for(int i = 0; i < 15; i++){
        puntarreglo[i]=&arreglo[i];
    }
    cout << "\nSe han guardado las posiciones correctamente\n\n";
    paso2 = 1;
    return;
}

void opcion3(){ // imprime el resultado de la tabla junto con la posicion
    cout << "\nTabla de multiplicar del " << tabla << " desde el " << inicio << " hasta " << inicio+15 << "\n\n";
    for(int i = 0;i < 15; i++){
        cout << "Operacion: " << tabla << "*" << *puntarreglo[i]/tabla << endl;
        cout << "Valor: " << *puntarreglo[i] << endl;
        cout << "Direccion de memoria: " << puntarreglo[i] << "\n\n";
    }
    return;
}

void opcion4(){ // mueve de lugar la posicion
    int pos1, pos2, *temporal, tempo;
    cout << "\nIngrese el primer indice(0-14): ";
    cin >> pos1;
    while(pos1 < 0 || pos1>14){
        cout << "Ingrese una posicion valida\n";
        cin >> pos1;
    }
    cout << "Ingrese el segundo indice(0-14): ";
    cin >> pos2;
    while(pos2 < 0 || pos2 > 14 || pos2==pos1){
        cout << "Ingrese una posicion valida\n";
        cin >> pos2;
    }
    temporal = puntarreglo[pos1];
    puntarreglo[pos1]=puntarreglo[pos2];
    puntarreglo[pos2]=temporal;
    cout << "Se han cambiado las posiciones satisfactoriamente\n\n";
    return;
}

void opcion5(){ // ordena la tabla de manera ascendente
    int *aux,tempo;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j<15-1-i;j++){
            if(puntarreglo[j]>puntarreglo[j+1]){
                aux=puntarreglo[j];
                puntarreglo[j]=puntarreglo[j+1];
                puntarreglo[j+1]=aux;
            }
        }
    }
    cout << "\nSe ha organizado ascendentemente correctamente\n\n";
    return;
}

void opcion6(){ // ordena de manera ascendente
    int *aux, tempo;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j<15-1-i;j++){
            if(puntarreglo[j]<puntarreglo[j+1]){
                aux=puntarreglo[j];
                puntarreglo[j]=puntarreglo[j+1];
                puntarreglo[j+1]=aux;
            }
        }
    }
    cout << "\nSe ha organizado descendentemente correctamente\n\n";
    return;
}
