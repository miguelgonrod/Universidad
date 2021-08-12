#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Usuarios{
    int id;
    char username[50];
    char password[20];
    int role;
    char verified;
    char blocked;
};

void admin();
void registro();
void login();

int main(){
    int opcion;
    while(true){
        cout << "Deseas 1)Iniciar-sesion 2)registrarse 3)salir: \n";
        cin >> opcion;
        if(opcion==1){
        }
        else if(opcion==2){
            registro();
        }
        else if(opcion==3){
            break;
        }
        else{
            cout << "Opcion invalida, ingrese una nuevamente\n";
        }
    }
    return 0;
}

void admin(){
}

void registro(){
    int cont = 0;
    Usuarios informacion;
    string temp;
    fstream Leer("Usuarios.txt", ios::in | ios::binary);
    if(Leer.good()==true){
        while(!Leer.eof()){
            Leer.read((char *)&informacion,sizeof(informacion));
        }
        cont = informacion.id + 1;
    }
    Leer.close();
    fstream Guardar("Usuarios.txt", ios::app | ios::in | ios::binary);
    cout << "Ingrese el username: ";
    getline(cin>>ws,temp);
    strcpy(informacion.username,temp.c_str());
    cout << "Ingrese la contraseña: ";
    getline(cin>>ws,temp);
    strcpy(informacion.password,temp.c_str());
    cout << "Ingrese el rol 1)admin 2)comprador 3)consulta: ";
    cin >> informacion.role;
    while(informacion.role < 1 || informacion.role > 3){
        cout << "Opcion incorrecta, ingrese otra nuevamente\n";
        cin >> informacion.role;
    }
    informacion.verified = 'F';
    informacion.blocked = 'F';
    informacion.id = cont;
    Guardar.write((char *)&informacion, sizeof(informacion));
    Guardar.close();
    cout << "Se le solicitará acceso al administrador\n\n";
    return;
}

int login(){
    Usuarios informacion;
    int errores = 0, rol = 0;
    char username[50], password[20];
    string temp;
    fstream Leer("Usuarios.txt", ios::in | ios::binary);
    if(Leer.good()==true){
        cout << "Ingrese el username: ";
        getline(cin>>ws, temp);
        strcpy(username,temp.c_str());
        while(!Leer.eof()){
            Leer.read((char *)&informacion,sizeof(informacion));
            if(strcmp(username,informacion.username)){
                if(informacion.blocked=='T'){
                    cout << "Su cuenta ha sido suspendida por escribir la contraseña mal tres veces, contactese con un administrador\n\n";
                }
                else{
                    while(errores!=3){
                        cout << "Ingrese la contraseña: ";
                        getline(cin>>ws,temp);
                        strcpy(password,temp.c_str());
                        if(!strcmp(password,informacion.password)){
                            cout << "Contraseña incorrecta\n";
                            errores++;
                        }
                        else{
                            rol = informacion.rol;
                            break;
                        }
                    }
                    if(errores==3){
                        cout << "Ha realizado 3 intentos incorrectos, su cuenta ha sido suspendida";
                    }
                }
            }
        }
    }
    else{
        cout << "No tiene ningun usuario creado\n\n";
    }
    return rol;
}
