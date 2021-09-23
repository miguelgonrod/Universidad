#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Usuarios{
    int id;
    string username;
    string password;
    int role;
    char verified;
    char blocked;
};

void admin();
void registro();
int login();

int main(){
    int opcion, rol;
    while(true){
        cout << "Deseas 1)Iniciar-sesion 2)registrarse 3)salir: \n";
        cin >> opcion;
        if(opcion==1){
            rol=login();
            if(rol==1){}
            else if(rol==2){}
            else if(rol==3){}
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
    getline(cin>>ws,informacion.username);
    cout << "Ingrese la contraseña: ";
    getline(cin>>ws,informacion.password);
    cout << "Ingrese el rol 1)admin 2)comprador 3)consulta: ";
    cin >> informacion.role;
    while(informacion.role < 1 || informacion.role > 3){
        cout << "Opcion incorrecta, ingrese otra nuevamente\n";
        cin >> informacion.role;
    }
    informacion.verified = 'V';
    informacion.blocked = 'F';
    informacion.id = cont;
    Guardar.write((char *)&informacion, sizeof(informacion));
    Guardar.close();
    cout << "Se le solicitará acceso al administrador\n\n";
    return;
}

int login(){
    Usuarios informacion;
    int errores = 0, rol = 0, log=0;
    char username_c[50], username_s[50], password_c[50], password_s[50];
    string password_act;
    string temp;
    string username_act;
    fstream Leer("Usuarios.txt", ios::in | ios::binary);
    if(Leer.good()==true){
        cout << "Ingrese el username: ";
        getline(cin>>ws, username_act);
        strcpy(username_c,username_act.c_str());
        strcpy(username_s,informacion.username.c_str());
        while(!Leer.eof()){
            Leer.read((char *)&informacion,sizeof(informacion));
            if(strcmp(username_c,username_s)!=0){
                if(informacion.blocked=='T'){
                    cout << "Su cuenta ha sido suspendida por escribir la contraseña mal tres veces, contactese con un administrador\n\n";
                }
                else{
                    while(errores!=3){
                        cout << "Ingrese la contraseña: ";
                        getline(cin>>ws,password_act);
                        strcpy(password_c,password_act.c_str());
                        strcpy(password_s,informacion.password.c_str());
                        if(strcmp(password_c,password_s)){
                            rol = informacion.role;
                            log=1;
                            break;
                        }
                        else{
                            cout << "Contraseña incorrecta\n";
                            errores++;
                        }
                    }
                    if(errores==3){
                        cout << "Ha realizado 3 intentos incorrectos, su cuenta ha sido suspendida";
                    }
                }
            }
            else{
                cout << "El usuario no existe\n";
            }
            if(log==1){
                break;
            }
        }
    }
    else{
        cout << "No tiene ningun usuario creado\n\n";
    }
    return rol;
}
