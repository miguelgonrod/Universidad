#include <iostream>
using namespace std;

struct Alumnos{
    string nombre;
    float nota;
};

void ingresarDatos(Alumnos clase[11][50]);
void promedios(Alumnos clase[11][50]);
void imprimirPuntajes(Alumnos clase[11][50]);

int maxAlumn = 50;
float promedio = 0;
float promediosClases[12];
int mayor[12];
int cantClases = 11;
int tamClase[11];

int main(){
    Alumnos colegio[11][50];
    ingresarDatos(colegio);
    promedios(colegio);
    imprimirPuntajes(colegio);
    return 0;
}

void ingresarDatos(Alumnos clase[11][50]){
    for(int i = 0; i < cantClases; i++){
        cout << "Llene la informacion del grado " << i+1 << endl;
        cout << "Cuantos estudiantes hay en el grado " << i+1 << "?: ";
        cin >> tamClase[i];
        while(tamClase[i] < 1 || tamClase[i] > maxAlumn){
            cout << "Ingrese un numero valido (1-" << maxAlumn << "): ";
            cin >> tamClase[i];
        }
        for(int j = 0; j < tamClase[i]; j++){
            cout << "Ingrese el nombre del estudiante " << j+1 << ":\n";
            getline(cin>>ws,clase[i][j].nombre);
            cout << "Ingrese la nota del estudiante " << j+1 << ": ";
            cin >> clase[i][j].nota;
            if(j==0){
                mayor[i] = j;
            }
            if(clase[i][j].nota > clase[i][mayor[i]].nota){
                mayor[i] = j;
            }
        }
    }
    return;
}

void promedios(Alumnos clase[11][50]){
    for(int i = 0; i < cantClases; i++){
        promedio = 0;
        for(int j = 0; j < tamClase[i]; j++){
            promedio += clase[i][j].nota;
        }
        promediosClases[i] = promedio/tamClase[i];
    }
    promedio = 0;
    for(int i = 0; i < cantClases; i++){
        promedio += promediosClases[i];
    }
    promediosClases[12] = promedio/cantClases;
    return;
}

void imprimirPuntajes(Alumnos clase[11][50]){
    int maxNota[11][50];
    int contador[11];
    int contador2 = 0;
    int supremo[550];
    float maxValor = 0;
    supremo[0] = 0;
    cout << "\n";
    for(int i = 0; i < cantClases; i++){
        cout << "Promedio grado " << i+1 << ": " << promediosClases[i] << endl;
    }
    cout << "Promedio del colegio: " << promediosClases[12] << "\n\n";
    for(int i = 0; i < 11; i++){
        maxNota[i][0]=0;
    }
    for(int i = 0; i < cantClases; i++){
        contador[i] = 0;
        for(int j = 0; j < tamClase[i]; j++){
            if(clase[i][j].nota == clase[i][mayor[i]].nota){
                maxNota[i][contador[i]] = j;
                contador[i]++;
            }
        }
        for(int j = 0; j < contador[i]; j++){
            if(clase[i][maxNota[i][j]].nota > maxValor){
                maxValor = clase[i][maxNota[i][j]].nota;
            }
            cout << "Nombre: " << clase[i][maxNota[i][j]].nombre << " curso: " << i+1 << " Nota: " << clase[i][maxNota[i][j]].nota << endl;
        }
    }
    cout << "\nMejor/es del Colegio\n";
    for(int i = 0; i < cantClases; i++){
        for(int j = 0; j < contador[i]; j++){
            if(clase[i][maxNota[i][j]].nota == maxValor){
                cout << "Nombre: " << clase[i][maxNota[i][j]].nombre << " Clase: " << i+1 << " Nota: " << clase[i][maxNota[i][j]].nota << endl;
            }
        }
    }
    return;
}
