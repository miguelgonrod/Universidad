#include <iostream>
using namespace std;

char respuestas[20];
char respuestasAlum[20];
int calificaciones[20];
int idAlumnos[20];
int personas;

void calificacion(int num);
void imprimir();

int main(){
    for(int i = 0; i < 20; i++){
        cout << "Ingrese la respuesta de la pregunta " << i+1 << " (v/f): ";
        cin >> respuestas[i];
    }
    cout << "Cuantos estudiantes presentaron la prueba?: ";
    cin >> personas;
    for(int i = 0; i < personas; i++){
        calificacion(i);
    }
    imprimir();
    return 0;
}

void calificacion(int num){
    int grade = 0;
    cout << "Ingrese el id del usuario: ";
    cin >> idAlumnos[num];
    for(int i = 0; i < 20;i++){
        cout << "Ingrese la respuesta " << i+1 << " del alumno " << num << ": ";
        cin >> respuestasAlum[i];
    }
    for(int i = 0; i < 20; i++){
        if(respuestasAlum[i]==respuestas[i]){
            grade++;
        }
    }
    calificaciones[num] = (grade*100)/20;
    return;
}

void imprimir(){
    for(int i = 0; i < personas; i++){
        cout << "id: " << idAlumnos[i] << " nota: ";
        if(calificaciones[i] < 60 && calificaciones[i] >= 0){
            cout << "F" << endl;
        }
        else if(calificaciones[i] < 70 && calificaciones[i] >= 60){
            cout << "D" << endl;
        }
        else if(calificaciones[i] < 80 && calificaciones[i] >= 70){
            cout << "C" << endl;
        }
        else if(calificaciones[i] < 90 && calificaciones[i] >= 80){
            cout << "B" << endl;
        }
        else if(calificaciones[i] <= 100 && calificaciones[i] >= 90){
            cout << "A" << endl;
        }
        else{
            cout << "Imposible" << endl;
        }
    }
    return;
}
