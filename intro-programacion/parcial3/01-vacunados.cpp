#include <iostream>
using namespace std;

struct Pacientes(){
    string nombres;
    string apellidos;
    int edad;
    char vacunado; // S o N dosis 1
    char vacunado2; //S o N dosis2
    int identificacion;
    int telefono;
    string eps;
    int codigoVacuna;
    int fecha1[3]; // dia mes año
    int fecha2[3];
};

int dia = 0;
int mes = 0;
int año = 0;

int main(){
    Pacientes usuario[20];
    int cantUsuarios;
    int cantVacunas
    return 0;
}

int estadisticasVacunas(struct Pacientes usuario[20], int cantUsuarios, int cantVacunas){
    int vacunas[cantVacunas][2] = 0;
    for(int i = 0; i < cantVacunas; i++){
        for(int j = 0; j < 2; j++){
            vacunas[i][j]=0;
        }
    }

    for(int i = 0; i < cantUsuarios; i++){
        if(usuario[i].vacunado == 'S'){
            vacunas[usuario[i].vacunado2 == 'S'][0] ++;
            if(usuario[i].fecha2 != 0){
                vacunas[usuario[i].codigoVacuna][1]++;
            }
        }
    }
    return vacunas;
}
