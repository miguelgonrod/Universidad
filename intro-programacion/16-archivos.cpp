#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAX_LETRAS = 50;
const int MAX_NOTAS = 3;
string temp;

FILE *archivo1;

struct Estudiante{
    int ID;
    char nombre[MAX_LETRAS];
    float notas[MAX_NOTAS];
};

int main(){
    Estudiante estu1;

    int id_temp;
    cout << "Ingrese el id del estudiante que desea adicionar: ";
    cin >> id_temp;
    archivo1 = fopen("introProg_14753.txt", "r+");
    if(archivo1 == NULL){
        archivo1 = fopen("introProg_14753.txt", "w");
        fclose(archivo1);
        archivo1 = fopen("introProg_14753.txt", "r+");
    }

    // 1 posicion: donde se carga lo que se lea, 2 posicion: tamaño de lectura, 3 posicion: cuantos registros se llenan al tiempo, 4 posicion: archivo a leer
    fread(&estu1,sizeof(estu1),1,archivo1);
    while(!feof(archivo1)){
        if(estu1.ID == id_temp){
            cout << "El registro ya existe";
            fclose(archivo1);
            return 0;
        }
        fread(&estu1,sizeof(estu1),1,archivo1);
    }
    cout << "OK, el registro no existe. vamos a crearlo\n";
    estu1.ID = id_temp;
    cout << "ingrese el nombre del estudiante: ";
    getline(cin>>ws,temp);
    strcpy(estu1.nombre, temp.c_str());
    for(int i = 0; i<MAX_NOTAS; i++){
        cout << "Ingrese la nota " << i+1 << ": ";
        cin >> estu1.notas[i];
    }
    fwrite(&estu1, sizeof(estu1), 1, archivo1);
    cout << "archivo almacenado con exito";
    fclose(archivo1);

    return 0;
}
