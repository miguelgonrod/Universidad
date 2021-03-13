#include <stdio.h>
#include <stdlib.h>
int main(){
    int clave[4]={};
    int claveIngresada[4]={};
    int intentos = 3;
    printf("Ingrese la contraseña que desea almacenar, cada digito separado por un enter:\n");
    for(int i = 0; i<=3; i++){
        scanf("%d", &clave[i]);
    }
    system("clear");
    while(intentos>0){
        printf("Ingrese su contraseña, cada digito separado por un enter, tiene %d intentos:\n", intentos);
        for(int i = 0; i <= 3; i++){
            scanf("%d", &claveIngresada[i]);
        }
        if((clave[0]==claveIngresada[0]) && (clave[1]==claveIngresada[1]) && (clave[2]==claveIngresada[2]) && (clave[3]==claveIngresada[3])){
            printf("Correcto");
            break;
        }
        else if(intentos > 1){
            printf("Incorrecto, intenta de nuevo\n");
            intentos--;
        }
        else{
            printf("Incorrecto");
            intentos--;
        }
    }
    return 0;
}
