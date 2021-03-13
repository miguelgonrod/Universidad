#include <stdio.h>
#include <stdlib.h>
int main(){
    char nombre[50]={0};
    char apellido[50];
    printf("Ingresa tus dos nombres\n");
    scanf("%[^\n]", nombre);
    getchar(); // en c cuando uno pone enter lo reconoce como caracter, sin esto el proximo scanf no funciona

    printf("Hola %s \n", nombre);

    printf("Ingresa tus apellidos\n");
    scanf("%[^\n]", apellido);
    getchar();

    printf("hola %s %s", nombre, apellido);
    return 0;
}
