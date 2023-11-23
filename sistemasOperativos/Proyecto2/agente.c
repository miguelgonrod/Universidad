/*
Archivo: agente.c
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: implementación de las funcionen que permiten crear los pipes de cada agente, leer archivos y enviar solicitudes
Fecha última modificación: 19/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "agente.h"

/*
Función: main
Parámetros de Entrada: numero de parametros y parametros de entrada (argv)
Valor de salida: retorna 0 si el programa se ejecuta correctamente
Descripción: Verifica que los parametros de entrada sean correctos, y llama a la función que carga los parametros, posteriormente se notifica al controlador que se ha creado el pipe, y se lee el archivo de solicitudes, para enviarlas al controlador.   
*/

int main(int argc, char *argv[]) {
    int fd, fd1, creado = 0, cuantos;
    FILE *file;

    char buffer[1024];

    mode_t fifo_mode = S_IRUSR | S_IWUSR;

    struct InfoSolicitud solicitud;
    solicitud.inicio = 0;
    solicitud.numPersonas = 0;

    if(argc != 7){
        printf("Error: Numero de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./agente -s [nombre] -a [archivosolicitudes] -p [piperecibe]\n");
        exit(1);
    }
    CheckParameters(argv);

    strcpy(solicitud.nombre, nombre);
    strcpy(solicitud.nombrePipe, nombre);

    if (mkfifo (solicitud.nombrePipe, fifo_mode) == -1) {
        perror("Server mkfifo:");
        exit(1);
    }

    if((file = fopen(archivoSolicitudes, "r")) == NULL){
        perror("Error al abrir el archivo.\n");

        exit(1);
    }

    do { 
        fd = open(pipeRecibe, O_WRONLY);
        if (fd == -1) {
            perror("pipe");
            printf(" Se volvera a intentar despues\n");
	        sleep(1);        
        } 
        else {
            printf("Se ha abierto el pipe %s\n", pipeRecibe);
            creado = 1;
        }
    } while (creado == 0);

    write(fd, &solicitud, sizeof(solicitud));
    printf("Nombre: %s\n", solicitud.nombre);
    if ((fd1 = open(solicitud.nombrePipe, O_RDONLY)) == -1) {
        perror("Agente  Abriendo el segundo pipe: ");
        exit(1);
    } 

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        size_t longitud = strlen(buffer);
        if (longitud > 0 && buffer[longitud - 1] == '\n') {
            buffer[longitud - 1] = '\0';
        }

        tokenizador(buffer);
        printf("Línea leída: %s\n", buffer);

        solicitud.inicio = horaInicio;
        solicitud.numPersonas = cantPersonas;
        write(fd, &solicitud, sizeof(solicitud));

        cuantos = read(fd1, estado, 100);
        if (cuantos < 0) {
            perror("Error al leer el segundo pipe");
            exit(1);
        }
        else {
            estado[cuantos] = '\0';
            printf("Familia: %s \nHora de Inicio: %d \nCantidad de personas: %d \nEstado: %s", nombreFamilia, horaInicio, cantPersonas, estado);
        }

        strcpy(estado, "");

        sleep(2);
    }

    fclose(file);

    printf("Agente %s termina.\n", nombre);

    return 0;
}

/*
Función: checkParameters
Parámetros de Entrada: parametros de entrada (argv)
Valor de salida: NULL
Descripción: Verifica que los parametros de entrada sean correctos, y los carga a las variables publicas respectivas.
*/

void CheckParameters(char *parameters[]){
    int numC, numF, numH, porc;
    if(parameters[1][1] == 's'){
        strcpy(nombre, parameters[2]);
    }
    else if(parameters[1][1] == 'a'){
        strcpy(archivoSolicitudes, parameters[2]);
    }
    else if(parameters[1][1] == 'p'){
        strcpy(pipeRecibe, parameters[2]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./agente -s [nombre] -a [archivosolicitudes] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[3][1] == 's'){
        strcpy(nombre, parameters[4]);
    }
    else if(parameters[3][1] == 'a'){
        strcpy(archivoSolicitudes, parameters[4]);
    }
    else if(parameters[3][1] == 'p'){
        strcpy(pipeRecibe, parameters[4]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./agente -s [nombre] -a [archivosolicitudes] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[5][1] == 's'){
        strcpy(nombre, parameters[6]);
    }
    else if(parameters[5][1] == 'a'){
        strcpy(archivoSolicitudes, parameters[6]);
    }
    else if(parameters[5][1] == 'p'){
        strcpy(pipeRecibe, parameters[6]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./agente -s [nombre] -a [archivosolicitudes] -p [piperecibe]\n");
        exit(1);
    }
}

/*
Función: tokenizador
Parámetros de Entrada: punteros de char que contienen la linea a tokenizar
Valor de salida: NULL
Descripción: Tokeniza tomando en cuenta el caracter ',' y carga los valores a las variables globales respectivas.
*/

void tokenizador(char *linea){
    int posicion = 0;
    char cadenaTemporal[2];
    cadenaTemporal[0] = ' ';
    cadenaTemporal[1] = '\0';

    horaInicio = 0;
    cantPersonas = 0;
    strcpy(nombreFamilia, "");

    for(int caracter = 0; linea[0] != '\0'; caracter++){
        if(linea[caracter] == ','){
            posicion++;
        }
        else{
            if(posicion == 0){
                cadenaTemporal[0] = linea[caracter];
                strcat(nombreFamilia, cadenaTemporal);
            }
            else if(posicion == 1){
                cadenaTemporal[0] = linea[caracter];
                horaInicio = horaInicio * 10 + atoi(cadenaTemporal);
            }
            else if(posicion == 2){
                cadenaTemporal[0] = linea[caracter];
                cantPersonas = cantPersonas * 10 + atoi(cadenaTemporal);
            }
        }
    }
}