#include <iostream>
#include <time.h>
using namespace std;

int ranNum[4]={0, 0, 0, 0};
int adiNum[4]={0, 0, 0, 0};
int picas=0, fijas=0;

void generarNums();
void calPicas();
void calFijas();
void inicio();
int rendirse();

int main(){
    char again = 's';
    while(again != 'n'){
        generarNums();
        inicio();
        cout << "Deseas jugar de nuevo? (s/n)\n";
        cin >> again;
    }
    return 0;
}

void generarNums(){
    srand(time(NULL));
    ranNum[0] = rand() % 9 + 1;
    ranNum[1] = rand() % 10;
    ranNum[2] = rand() % 10;
    ranNum[3] = rand() % 10;
    while(ranNum[1] == ranNum[0]){
        ranNum[1] = rand() % 10;
    }
    while(ranNum[2] == ranNum[1] || ranNum[2] == ranNum[0]){
        ranNum[2] = rand() % 10;
    }
    while(ranNum[3] == ranNum[2] || ranNum[3] == ranNum[1] || ranNum[3] == ranNum[0]){
        ranNum[3] = rand() % 10;
    }
    return;
}

void inicio(){
    int turnos;
    cout << "Ingresa cuantos turnos quieres que hayan, el 0 se interpretara como infinitos: \n";
    cin >> turnos;
    while(turnos < 0){
        cout << "Ingresa una opcion valida:\n";
        cin >> turnos;
    }
    if(turnos == 0){
        while(true){
            cout << "Ingrese 4 numeros diferentes entre 0 y 9 de esta manera 1 2 3 4 \n";
            cin >> adiNum[0] >> adiNum[1] >> adiNum[2] >> adiNum[3];
            calFijas();
            calPicas();
            if(fijas == 4){
                cout << "Correcto, ha adivinado\n";
                break;
            }
            cout << "Tiene " << fijas << " fijas y " << picas << " picas\n";
            fijas=0;
            picas=0;
            if(rendirse() == 1){
                cout << "El numero era " << ranNum[0] << ranNum[1] << ranNum[2] << ranNum[3] << endl;
                break;
            }
        }
    }
    else{
        while(turnos > 0){
            cout << turnos << " turnos restantes\n";
            cout << "Ingrese 4 numeros diferentes entre 0 y 9 de esta manera 1 2 3 4\n";
            cin >> adiNum[0] >> adiNum[1] >> adiNum[2] >> adiNum[3];
            calFijas();
            calPicas();
            if(fijas == 4){
                cout << "Correcto has adivinado\n";
                break;
            }
            cout << "Tiene " << fijas << " fijas y " << picas << " picas\n";
            fijas=0;
            picas=0;
            turnos--;
            if(rendirse() == 1){
                cout << "El numero era " << ranNum[0] << ranNum[1] << ranNum[2] << ranNum[3] << endl;
            }
        }
    }
    return;
}

void calFijas(){
    for(int i = 0; i <= 3; i++){
        if(adiNum[i] == ranNum[i]){
            fijas++;
        }
    }
    return;
}

void calPicas(){
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            if(adiNum[i]==ranNum[j] && i != j){
                picas++;
            }
        }
    }
    return;
}

int rendirse(){
    char rendimiento;
    cout << "Deseas rendirte? (s/n)\n";
    cin >> rendimiento;
    if(rendimiento == 's'){
        return 1;
    }
    else{
        return 0;
    }
}
