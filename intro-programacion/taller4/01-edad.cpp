#include <iostream>
#include <ctime>
using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);

bool bisiesto(int año);
void fecha_valida();
void calcular_edad(int diaAct, int mesAct, int añoAct, int diaNac, int mesNac, int añoNac);

int diaAct, mesAct, añoAct, diaNac, mesNac, añoNac;
int year = 1900 + ltm->tm_year;
int month = 1 + ltm->tm_mon;
int day = ltm->tm_mday;

int main(){
    fecha_valida();
    calcular_edad(diaAct, mesAct, añoAct, diaNac, mesNac, añoNac);
    return 0;
}

bool bisiesto(int año){
    if((año % 4 == 0) || ((año % 100 == 0) && (año % 400 == 0))){
        return true;
    }
    else{
        return false;
    }
}

void fecha_valida(){
    bool añoMayor = false, ciclo = false;
    while(añoMayor == false){
        while(ciclo == false){
            cout << "Ingrese su fecha de nacimiento (dia/mes/año) separados por un espacio\n";
            cin >> diaNac >> mesNac >> añoNac;
            if(bisiesto(añoNac) == true){
                if(añoNac >= 0){
                    if(mesNac > 1 && mesNac <= 12){
                        if(mesNac == 2 && diaNac > 0 && diaNac <= 29){
                            ciclo = true;
                        }
                        else if((mesNac == 4 || mesNac == 6 || mesNac == 9 || mesNac == 11) && diaNac > 0 && diaNac <= 30){
                            ciclo = true;
                        }
                        else if((mesNac == 1 || mesNac == 3 || mesNac == 5 || mesNac == 7 || mesNac == 8 || mesNac == 10 || mesNac == 12) && diaNac > 0 && diaNac <=31){
                            ciclo = true;
                        }
                        else{
                            cout << "Ingrese una fecha valida\n";
                        }
                    }
                    else{
                        cout << "Ingrese una fecha valida\n";
                    }
                }
                else{
                    cout << "Ingrese una fecha valida\n";
                }
            }
            else{
                if(añoNac >= 0){
                    if(mesNac > 1 && mesNac <= 12){
                        if(mesNac == 2 && diaNac > 0 && diaNac <= 28){
                           ciclo = true;
                        }
                        else if((mesNac == 4 || mesNac == 6 || mesNac == 9 || mesNac == 11) && diaNac > 0 && diaNac <= 30){
                            ciclo = true;
                        }
                        else if((mesNac == 1 || mesNac == 3 || mesNac == 5 || mesNac == 7 || mesNac == 8 || mesNac == 10 || mesNac == 12) && diaNac > 0 && diaNac <=31){
                            ciclo = true;
                        }
                        else{
                            cout << "Ingrese una fecha valida\n";
                        }
                    }
                    else{
                        cout << "Ingrese una fecha valida\n";
                    }
                }
                else{
                    cout << "Ingrese una fecha valida\n";
                }
            }
            if(añoNac > year){
                ciclo = false;
                cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
            }
            else if(añoNac == year){
                if(mesNac > month){
                    ciclo = false;
                    cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
                }
                else if(mesNac == month){
                    if(diaNac > day){
                        ciclo = false;
                        cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
                    }
                }
            }
        }
        ciclo = false;
        while(ciclo == false){
            cout << "Ingrese la fecha actual (dia/mes/año) separados por un espacio\n";
            cin >> diaAct >> mesAct >> añoAct;
            if(bisiesto(añoAct) == true){
                if(añoAct >= 0){
                    if(mesAct > 1 && mesAct <= 12){
                        if(mesAct == 2 && diaAct > 0 && diaAct <= 29){
                            ciclo = true;
                        }
                        else if((mesAct == 4 || mesAct == 6 || mesAct == 9 || mesAct == 11) && diaAct > 0 && diaAct <= 30){
                            ciclo = true;
                        }
                        else if((mesAct == 1 || mesAct == 3 || mesAct == 5 || mesAct == 7 || mesAct == 8 || mesAct == 10 || mesAct == 12) && diaAct > 0 && diaAct <=31){
                            ciclo = true;
                        }
                        else{
                            cout << "Ingrese una fecha valida\n";
                        }
                    }
                    else{
                        cout << "Ingrese una fecha valida\n";
                    }
                }
                else{
                    cout << "Ingrese una fecha valida\n";
                }
            }
            else{
                if(añoAct >= 0){
                    if(mesAct > 1 && mesAct <= 12){
                        if(mesAct == 2 && diaAct > 0 && diaAct <= 28){
                            ciclo = true;
                        }
                        else if((mesAct == 4 || mesAct == 6 || mesAct == 9 || mesAct == 11) && diaAct > 0 && diaAct <= 30){
                            ciclo = true;
                        }
                        else if((mesAct == 1 || mesAct == 3 || mesAct == 5 || mesAct == 7 || mesAct == 8 || mesAct == 10 || mesAct == 12) && diaAct > 0 && diaAct <=31){
                            ciclo = true;
                        }
                        else{
                            cout << "Ingrese una fecha valida\n";
                        }
                    }
                    else{
                        cout << "Ingrese una fecha valida\n";
                    }
                }
                else{
                    cout << "Ingrese una fecha valida\n";
                }
            }
            if(añoAct > year){
                ciclo = false;
                cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
            }
            else if(añoAct == year){
                if(mesAct > month){
                    ciclo = false;
                    cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
                }
                else if(mesAct == month){
                    if(diaAct > day){
                        ciclo = false;
                        cout << "Ingrese una fecha valida, fecha maxima: " << day << " " << month << " " << year << endl;
                    }
                }
            }
        }
        ciclo = false;
        if(añoAct > añoNac){
            añoMayor = true;
        }
        else if(añoAct == añoNac){
            if(mesAct > mesNac){
                añoMayor = true;
            }
            else if(mesAct == mesNac){
                if(diaAct > diaNac){
                    añoMayor = true;
                }
                else if(diaAct == diaNac){
                    añoMayor = true;
                }
                else{
                    cout << "Ingrese fechas validas\n";
                }
            }
            else{
                cout << "Ingrese fechas validas\n";
            }
        }
        else{
            cout << "Ingrese fechas validas\n";
        }
    }
    return;
}


void calcular_edad(int diaAct, int mesAct, int añoAct, int diaNac, int mesNac, int añoNac){
    int años, meses, dias;
    if(mesAct > mesNac){
        años = añoAct - añoNac;
        if(diaAct >= diaNac){
            meses = mesAct - mesNac;
        }
        else{
            meses = mesAct - mesNac - 1;
        }
    }
    else if(mesAct == mesNac){
        if(diaAct >= diaNac){
            años = añoAct - añoNac;
            meses = 0;
        }
        else{
            años = añoAct - añoNac - 1;
            meses = 11;
        }
    }
    else{
        años = añoAct - añoNac - 1;
        if(diaAct >= diaNac){
            meses = 12 - (mesNac - mesAct);
        }
        else{
            meses = 12 - (mesNac - mesAct - 1);
        }
    }
    cout << "Usted tiene: " << años << " años y " << meses << " meses\n";
    return;
}

