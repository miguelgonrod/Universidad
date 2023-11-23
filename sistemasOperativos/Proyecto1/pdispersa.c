/*
Archivo: pdispersa.c
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: implementación de las funcionen que permiten manejar el archivo,
y cargar los parametros
Fecha última modificación: 11/09/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

#include "pdispersa.h"

#define ARCH1 "archivo1.txt"
#define ARCH2 "archivo2.txt"

/*
Función: main
Parámetros de Entrada: numero de parametros y parametros de entrada (argv)
Valor de salida: retorna 0 si el programa se ejecuta correctamente
Descripción: Verifica que los parametros de entrada sean correctos, y llama a la función que carga los parametros,
lee el archivo y crea la matriz "dispersa".
*/

int main(int argc, char *argv[])
{
    datosProceso p1;
    p1.fInicial = 0;
    p1.cInicial = 0;
    p1.fFinal = 0;
    p1.cFinal = -1;

    datosProceso p2;
    p2.fInicial = 0;
    p2.cInicial = 0;
    p2.fFinal = 0;
    p2.cFinal = -1;

    FILE *fd;
    FILE *arch1;
    FILE *arch2;

    int *pipe1 = (int*) malloc(2*sizeof(int));

    int status1, status2, resultadoParcial, sumaP1, sumaP2, bandera, count;
    float resultadoPorcentaje;

    if(argc != 11){
        printf("Error: Numero de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }
    CheckParameters(argv);

    matriz = (int **)malloc(num_filas * sizeof(int *));
    for (int i = 0; i < num_filas; i++){
        matriz[i] = (int *)malloc(num_columnas * sizeof(int));
    }

    fd = fopen(archivo, "r");

    trabajoProcesos = ((num_filas * num_columnas) / num_procesos) + 1;
    if( fd == NULL){
        perror("Error: ");
        exit(1);
    }

    cargarDatos(fd, matriz, num_filas, num_columnas);
    fclose(fd);

    while(aux_numProcesos < num_procesos)
    {
        p1.fInicial = p2.fFinal;
        p1.cInicial = p2.cFinal+1;

        if(p1.cInicial >= num_columnas)
        {
            p1.fInicial+= p1.cInicial/ num_columnas;
            p1.cInicial = p1.cInicial%num_columnas;
        }

        p1.fFinal = p1.fInicial + trabajoProcesos / num_columnas;
        p1.cFinal = p1.cInicial + trabajoProcesos % num_columnas;

        if(p1.cFinal >= num_columnas)
        {
            p1.fFinal+= p1.cFinal/num_columnas;
            p1.cFinal = p1.cFinal%num_columnas;
        }

        if(p1.fFinal >= num_filas)
        {
           p1.fFinal = num_filas-1;
           p1.cFinal = num_columnas-1;
        }

        p2.cInicial = p1.cFinal+1;
        p2.fInicial = p1.fFinal;

        if(p2.cInicial >= num_columnas)
        {
            p2.fInicial+= p2.cInicial/num_columnas;
            p2.cInicial = p2.cInicial%num_columnas;
        }

        p2.fFinal = p2.fInicial + trabajoProcesos / num_columnas;
        p2.cFinal = p2.cInicial + trabajoProcesos % num_columnas;

        if(p2.cFinal >= num_columnas)
        {
            p2.fFinal+= p2.cFinal/num_columnas;
            p2.cFinal = p2.cFinal%num_columnas;
        }

        if(p2.fFinal >= num_filas)
        {
           p2.fFinal = num_filas-1;
           p2.cFinal = num_columnas-1;
        }

        pipe(pipe1);

        pid1 = fork();

        if (pid1 == 0)
        {
            bandera = 1;
            count = contarCeros(matriz, p1, num_columnas);
            if(count >= 255)
            {
                arch1 = fopen(archivo1, "w");
                fwrite(&count,sizeof(int),1, arch1);
                fclose(arch1);
                count = 255;
            }
            close(pipe1[0]);
            write(pipe1[1],&bandera,sizeof(int));
            close(pipe1[1]);
            exit(count);
        }
        
        else if (pid1 > 0)
        {
            pid2 = fork();

            if (pid2 == 0)
            {
                close(pipe1[1]);
                read(pipe1[0], &bandera, sizeof(int));
                close(pipe1[0]);
                count = 0;
                if(aux_numProcesos + bandera < num_procesos)
                {
                    count = contarCeros(matriz, p2, num_columnas);
                    if(count >= 255)
                    {
                        arch2 = fopen(archivo2, "w");
                        fwrite(&count,sizeof(int),1, arch2);
                        fclose(arch2);
                        count = 255;
                    }
                }
                exit(count);
            }
            else if (pid2 > 0)
            {
                aux_numProcesos+=2;
                waitpid(pid1, &status1, 0);
                waitpid(pid2, &status2, 0);

                sumaP1 = WEXITSTATUS(status1);
                sumaP2 = WEXITSTATUS(status2);
                if(sumaP1 == 255)
                {
                    arch1 = fopen(archivo1, "r");
                    fread(&sumaP1, sizeof(int),1, arch1);
                    fclose(arch1);
                }
                if(sumaP2 == 255)
                {
                    arch2 = fopen(archivo2, "r");
                    fread(&sumaP2, sizeof(int),1, arch2);
                    fclose(arch2);
                }
                resultadoParcial = sumaP1 + sumaP2;

                contador += resultadoParcial;
            }
            else
            {
                perror("Error en fork");
                exit(1);
            }
        }
        else
        {
            perror("Error en fork");
            exit(1);
        }
    }

    total = num_filas * num_columnas;
    resultadoPorcentaje = ((float)contador / total)*100;


    if(resultadoPorcentaje >= porcentaje)
    {
       printf("La matriz tiene un total de %d ceros (%f%%), por lo tanto se considera dispersa\n", contador, resultadoPorcentaje);
    }
    else
    {
        printf("La matriz tiene un total de %d ceros (%f%%), por lo tanto no se considera dispersa\n", contador, resultadoPorcentaje);
    }
    return 0;
}

/*
Función: cargarDatos
Parámetros de Entrada: Archivo de tipo FILE que contiene la matriz, la matriz vacia, el numero de filas y el numero de columnas
Valor de salida: Ninguno
Descripción: Carga los datos del archivo a la matriz
*/

void cargarDatos(FILE *archivo, int **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fscanf(archivo, "%d", &matriz[i][j]);
        }
    }
}

/*
Función: contarCeros
Parámetros de Entrada: matriz, estructura "datosProceso" que contiene el rango de filas y columnas, y el numero de columnas total
Valor de salida: retorna la cantidad de 0 que encontró en el rango
Descripción: Cuenta la cantidad de 0 que hay en el rango de filas y columnas
*/

int contarCeros(int **matriz, datosProceso rango, int columnas)
{
    int count = 0, j;
    for (int i = rango.fInicial; i <= rango.fFinal; i++)
    {
        j = rango.cInicial;
        if(i != rango.fInicial)
        {
            j = 0;
        }
        for (j; j < columnas; j++)
        {
            if (matriz[i][j] == 0)
            {
                count++;
            }

            if(j == rango.cFinal && i == rango.fFinal)
            {
                return count;
            }
        }
    }
    return count;
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
        num_procesos = atoi(parameters[2]);
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
        num_procesos = atoi(parameters[4]);
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
        num_procesos = atoi(parameters[6]);
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
        num_procesos = atoi(parameters[8]);
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
        num_procesos = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'p'){
        porcentaje = atoi(parameters[10]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        exit(1);
    }

    if(num_filas <= 0 || num_columnas <= 0 || num_procesos <= 0 || porcentaje <= 0 || porcentaje > 100 || num_procesos > num_filas){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./pdispersa -f [numero de filas] -c [numero de columnas] -a [ruta archivo] -n [numero de procesos] -p [porcentaje]\n");
        printf("Adicionalmente los valores de los argumentos deben ser positivos, y el porcentaje debe ser menor o igual a 100\n");
        exit(1);
    }
}