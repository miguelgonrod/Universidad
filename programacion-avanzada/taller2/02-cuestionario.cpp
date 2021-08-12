#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Datos{ //crea una estructura donde se almacene el numero de pregunta, la pregunta y las 4 respuestas
    int numPreg;
    char preg[200];
    char res1[50];
    char res2[50];
    char res3[50];
    char res4[50];
};

int main(){
    int opcion, bus, cont = 0;
    string temp;
    Datos preguntas;
    while(true){
        cout << "que opcion desea realizar 1)guardar 2)leer 3)salir: ";
        cin >> opcion;
        if(opcion==1){
            fstream Leer("Preguntas.txt", ios::in | ios::binary);
            while(!Leer.eof()){
                Leer.read((char *)&preguntas,sizeof(preguntas));
            }
            if(Leer.good()==true){
                cont = preguntas.numPreg + 1;
            }
            Leer.close();
            fstream Destino("Preguntas.txt", ios::app | ios::in | ios::binary); // abre el archivo Preguntas.txt en modo escritura binaria
            preguntas.numPreg = cont;
            cout << "Ingrese la pregunta (no use mas de 200 caracteres):\n";
            getline(cin>>ws, temp);
            strcpy(preguntas.preg, temp.c_str());
            cout << "Ingrese la respuesta a:\n";
            getline(cin>>ws, temp);
            strcpy(preguntas.res1, temp.c_str());
            cout << "Ingrese la respuesta b:\n";
            getline(cin>>ws,temp);
            strcpy(preguntas.res2, temp.c_str());
            cout << "Ingrese la respuesta c:\n";
            getline(cin>>ws, temp);
            strcpy(preguntas.res3, temp.c_str());
            cout << "Ingrese la respuesta d:\n";
            getline(cin>>ws, temp);
            strcpy(preguntas.res4, temp.c_str());
            Destino.write((char *)&preguntas,sizeof(preguntas)); // escribe en el archivo preguntas.txt el valor de la estructura de datos con el tamaño de la estructura
            cout << "Pregunta guardada correctamente\n\n";
            Destino.close(); // cierra el archivo
        }
        else if(opcion==2){
            int hay = 0;
            fstream Leer("Preguntas.txt", ios::in | ios::binary); // abre el archivo original en modo de lectura binaria
            cout << "Ingrese el numero de pregunta: ";
            cin >> bus;
            while(!Leer.eof()){ // recorre todo el archivo
                if(preguntas.numPreg==bus && hay==0){ // revisa si el numero de pregunta es el mismo que estamos buscando
                    cout << preguntas.numPreg << ") " << preguntas.preg << "\n    a) " << preguntas.res1 << "\n    b) " << preguntas.res2 << "\n    c) " << preguntas.res3 << "\n    d) " << preguntas.res4 << "\n\n";
                    hay = 1;
                }
                Leer.read((char *)&preguntas,sizeof(preguntas)); // lee el siguiente registro
            }
            if(hay == 0){
                cout << "Ese numero de pregunta no existe\n\n";
            }
            Leer.close(); // cierra el archivo
        }
        else if(opcion==3){
            break;
        }
        else{
            cout << "opcion incorrecta, ingrese otra nuevamente\n\n";
        }
    }
    return 0;
}
