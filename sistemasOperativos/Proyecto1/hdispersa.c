/*
Archivo: hdispersa.c
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: implementación de las funcionen que permiten manejar el archivo,
y cargar los parametros
Fecha última modificación: 25/09/2023
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>

#include "hdispersa.h"

/*
Función: main
Parámetros de Entrada: numero de parametros y parametros de entrada (argv)
Valor de salida: retorna 0 si el programa se ejecuta correctamente
Descripción: Verifica que los parametros de entrada sean correctos, y llama a la función que carga los parametros,
lee el archivo y crea la matriz "dispersa".
*/

int main(int argc, char *argv[]) {
    int unos = 0, numero, filasPorHilo, residuo, inicio, final, porcentajeSparse, error;
    double cerosTotales;

    if(argc != 11){
        printf("Error: Numero de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./hdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }
    CheckParameters(argv);

    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo.\n");
        return 1;
    }

    int **matrix = (int **)malloc(num_filas * sizeof(int *));
    for (int i = 0; i < num_filas; i++) {
        matrix[i] = (int *)malloc(num_columnas * sizeof(int));
        for (int j = 0; j < num_columnas; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
 

    pthread_t hilos[num_hilos];
    struct InfoHilos datosHilos[num_hilos];
    int contadorHilos[num_hilos];

    if (num_filas >= num_columnas){
        filasPorHilo = num_filas / num_hilos;
        residuo = num_filas % num_hilos;
        inicio = 0;

        for (int i = 0; i < num_hilos; i++) {
            final = inicio + filasPorHilo + (i < residuo ? 1 : 0);

            datosHilos[i].inicio = inicio;
            datosHilos[i].final = final;
            datosHilos[i].matriz = matrix;
            datosHilos[i].columnas = num_columnas;
            datosHilos[i].contador = &contadorHilos[i];

            error = pthread_create(&hilos[i], NULL, buscarUno, (void *)&datosHilos[i]);

            if (error){
                fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
                exit(-1);
            }

            inicio = final;
        }

        for (int i = 0; i < num_hilos; i++) {
            error = pthread_join(hilos[i], NULL);

            if (error){
                fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
                exit(-1);
            }
        }
        for (int i = 0; i < num_hilos; i++) {
            unos += contadorHilos[i];
        }

        cerosTotales = (double)(num_columnas * num_filas) - unos;
        porcentajeSparse = ((cerosTotales / (num_columnas * num_filas)) * 100);
        numero = (int) cerosTotales;

        if (porcentajeSparse >= porcentaje) {
            printf("La matriz tiene un total de %d ceros (%d%%), por lo tanto se considera dispersa\n", numero, porcentajeSparse);
        } 

        else {
            printf("La matriz tiene un total de %d ceros (%d%%), por lo tanto no se considera dispersa\n", numero, porcentajeSparse);
        }
    }

    else if (num_filas < num_columnas){
        filasPorHilo = num_filas / num_hilos;
        residuo = num_filas % num_hilos;
        inicio = 0;

        for (int i = 0; i < num_hilos; i++) {
            final = inicio + filasPorHilo + (i < residuo ? 1 : 0);

            datosHilos[i].inicio = inicio;
            datosHilos[i].final = final;
            datosHilos[i].matriz = matrix;
            datosHilos[i].columnas = num_columnas;
            datosHilos[i].contador = &contadorHilos[i];

            error = pthread_create(&hilos[i], NULL, buscarUno, (void *)&datosHilos[i]);
            if (error){
                fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
                exit(-1);
            }

            inicio = final;
        }

  
        for (int i = 0; i < num_hilos; i++) {
            error = pthread_join(hilos[i], NULL);
            if (error){
                fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
                exit(-1);
            }
        }
        for (int i = 0; i < num_hilos; i++) {
            unos += contadorHilos[i];
        }


        cerosTotales = (double)(num_columnas * num_filas) - unos;
        porcentajeSparse = ((cerosTotales / (num_columnas * num_filas)) * 100);
        numero = (int) cerosTotales;

        if (porcentajeSparse >= porcentaje) {
            printf("La matriz tiene un total de %d ceros (%d%%), por lo tanto se considera dispersa\n", numero, porcentajeSparse);
        }

        else {
            printf("La matriz tiene un total de %d ceros (%d%%), por lo tanto no se considera dispersa\n", numero, porcentajeSparse);
        }
    }

    return 0;
}

/*
Función: buscarUno
Parámetros de Entrada: apuntador a void que almacena la estructura con los datos de los hilos
Valor de salida: no tiene
Descripción: Busca los unos en la matriz
*/

void *buscarUno(void *arg) {
    struct InfoHilos *datos = (struct InfoHilos *)arg;
    int contador = 0;

    for (int i = datos->inicio; i < datos->final; i++) {
        for (int j = 0; j < datos->columnas; j++) {
            if (datos->matriz[i][j] == 1) {
                contador++;
            }
        }
    }

    *(datos->contador) = contador;
    pthread_exit(NULL);
}

/*
Función: CheckParameters
Parámetros de Entrada: arreglo de apuntadores a char, que almacena los parametros de entrada
Valor de salida: no tiene
Descripción: Verifica la posicion de los parametros y los carga a sus respectivas variables globales
*/

void CheckParameters(char *parameters[]){
    int numC, numF, numH, porc;
    if(parameters[1][1] == 'f'){
        num_filas = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 'c'){
        num_columnas = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 'a'){
        strcpy(archivo, parameters[2]);
    }
    else if(parameters[1][1] == 'n'){
        num_hilos = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 'p'){
        porcentaje = atoi(parameters[2]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(parameters[3][1] == 'f'){
        num_filas = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 'c'){
        num_columnas = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 'a'){
        strcpy(archivo, parameters[4]);
    }
    else if(parameters[3][1] == 'n'){
        num_hilos = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 'p'){
        porcentaje = atoi(parameters[4]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(parameters[5][1] == 'f'){
        num_filas = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 'c'){
        num_columnas = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 'a'){
        strcpy(archivo, parameters[6]);
    }
    else if(parameters[5][1] == 'n'){
        num_hilos = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 'p'){
        porcentaje = atoi(parameters[6]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(parameters[7][1] == 'f'){
        num_filas = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 'c'){
        num_columnas = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 'a'){
        strcpy(archivo, parameters[8]);
    }
    else if(parameters[7][1] == 'n'){
        num_hilos = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 'p'){
        porcentaje = atoi(parameters[8]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(parameters[9][1] == 'f'){
        num_filas = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'c'){
        num_columnas = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'a'){
        strcpy(archivo, parameters[10]);
    }
    else if(parameters[9][1] == 'n'){
        num_hilos = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'p'){
        porcentaje = atoi(parameters[10]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(num_filas <= 0 || num_columnas <= 0 || num_hilos <= 0 || porcentaje <= 0 || porcentaje > 100 || num_hilos > num_filas){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        printf("Adicionalmente los valores de los argumentos deben ser positivos, y el porcentaje debe ser menor o igual a 100\n");
        exit(1);
    }
}