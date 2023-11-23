/*
Archivo: controlador.c
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: implementación de las funcionen que permiten crear los hilos, pipes, parametros y las personas
Fecha última modificación: 19/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "controlador.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/*
Función: conteo_thread
Parámetros de Entrada: NULL
Valor de salida: NULL
Descripción: cuenta la hora simulada con respecto a los segundos reales que toma recorrer la hora y al finalizar imprime las metricas
*/

void *conteo_thread(void *arg) {
    float horaPico[2] = {-1, -1*100}, horaMenor[2] = {-1, 100};
    horaActual = horaInicio;
    while (1) {


        printf("Hora actual: %d\n", horaActual);

        if (horaActual >= horaFinal) {
            printf("Entra error");
            printf("El conteo ha alcanzado el máximo. Cerrando hilos.\n");
            for(int horaEvaluar = horaInicio; horaEvaluar < horaFinal; horaEvaluar++){
                if(horaPersonas[1][horaEvaluar - 7] > horaPico[1]){
                    horaPico[0] = horaEvaluar;
                    horaPico[1] = horaPersonas[1][horaEvaluar - 7];
                }
                if(horaPersonas[1][horaEvaluar - 7] < horaMenor[1]){
                    horaMenor[0] = horaEvaluar;
                    horaMenor[1] = horaPersonas[1][horaEvaluar - 7];
                }
            }
            printf("Hora Pico: %f \nHora Valle: %f \nSolicitudes rechazadas: %d \nSolicitudes aceptadas: %d \nSolicitudes Reprogramadas: %d", horaPico[0], horaMenor[0], negadas, aceptadas, reprogramadas);

            pthread_exit(NULL);
        }
                printf("entra3");   
                sleep(3);

                printf("entra2");   
        //sleep(segundosHora);
        horaActual++;
    }
    pthread_exit(NULL);
}

/*
Función: crear_pipes_thread
Parámetros de Entrada: NULL
Valor de salida: NULL
Descripción: Crea los pipes de escritura y lectura para cada solicitud y los almacena en un arreglo, adicionalmente realiza las verificaciones de si las solicitudes son aceptadas, rechazadas o reprogramadas
*/

void *crear_pipes_thread(void *arg) {
    int existe = 0, creado = 0, cuantos;
    int fd1[100];
    char *nombres[100], estado[100];
    struct InfoSolicitud solicitud;
    while (1) {

        existe = 0;
        creado = 0;
        // Lee un nuevo nombre de pipe de escritura
        printf("entra1");   
        cuantos = read(fd, &solicitud, sizeof(solicitud));
        printf("entra");   

        for(int numPipes = 0; numPipes < cuantosExisten; numPipes++){
            printf("entrax");
            if(strcmp(nombres[numPipes], solicitud.nombrePipe) == 0){
                existe = 1;
                break;
            }
        } 
                printf("entra");   

        if(existe == 0){
            strcpy(nombres[cuantos], solicitud.nombrePipe);
            printf("entra5");
            do {
                fd1[cuantos] = open(nombres[cuantos], O_WRONLY);
                if (fd == -1) {
                    perror("pipe");
                    printf(" Se volvera a intentar despues\n");
                    sleep(1);        
                } 
                else {
                    printf("Se ha abierto el pipe %s\n", nombres[cuantos]);
                    creado = 1;
                }
            } while (creado == 0);
            printf("Creado pipe de escritura: %s\n", nombres[cuantos]);
        }
        else{
            if(solicitud.numPersonas > totalPersonas){
                strcpy(estado, "Rechazado");
                negadas++;
            }
            else if(solicitud.inicio < horaActual){
                for(int hora = horaActual; hora <= horaFinal-2; hora++){
                    if(horaPersonas[1][hora - 7] + solicitud.numPersonas <= totalPersonas){
                        horaPersonas[0][hora - 7] += solicitud.numPersonas;
                        horaPersonas[0][hora - 6] += solicitud.numPersonas;
                        strcpy(estado, "reprogramado");
                        reprogramadas++;
                        break;
                    }
                    else{
                        strcpy(estado, "Rechazado");
                    }
                }
                if(strcmp(estado, "Rechazado") == 0){
                    negadas++;
                }
            }
            else{
                if(solicitud.inicio + 2 <= horaFinal){
                    if(horaPersonas[1][solicitud.inicio - 7] + solicitud.numPersonas <= totalPersonas){
                        horaPersonas[1][solicitud.inicio - 7] += solicitud.numPersonas;
                        horaPersonas[1][solicitud.inicio - 6] += solicitud.numPersonas;
                        strcpy(estado, "Aceptado");
                        aceptadas++;
                    }
                    else{
                        for(int hora = horaActual; hora <= horaFinal-2; hora++){
                            if(horaPersonas[1][hora - 7] + solicitud.numPersonas <= totalPersonas){
                                horaPersonas[0][hora - 7] += solicitud.numPersonas;
                                horaPersonas[0][hora - 6] += solicitud.numPersonas;
                                strcpy(estado, "reprogramado");
                                reprogramadas++;
                                break;
                            }
                            else{
                                strcpy(estado, "Rechazado");
                            
                            }
                        }
                        if(strcmp(estado, "Rechazado") == 0){
                            negadas++;
                        }
                    }
                }
                else{
                    strcpy(estado, "Rechazado");
                    negadas++;
                }
            }
            for(int numPipes = 0; numPipes < cuantosExisten; numPipes++){
                if(strcmp(nombres[numPipes], solicitud.nombrePipe) == 0){
                    write(fd1[numPipes], estado, sizeof(estado));
                    break;
                }
            }
        }
    }

    // Cierra el pipe de lectura
    for(int cantidadPipes = 0; cantidadPipes < cuantos; cantidadPipes++){
        close(fd1[cantidadPipes]);
    }
    close(fd);

    pthread_exit(NULL);
}

/*
Función: main
Parámetros de Entrada: numero de parametros y parametros de entrada (argv)
Valor de salida: retorna 0 si el programa se ejecuta correctamente
Descripción: Verifica que los parametros de entrada sean correctos, crea el pipe de lectura inicial, crea los hilos y espera a que terminen
*/

int main(int argc, char *argv[]) {
    int personasActual = 0;
    pthread_t hilo_conteo, hilo_pipes;
    int error1, error2, *salida;

    mode_t fifo_mode = S_IRUSR | S_IWUSR;

    if(argc != 11){
        printf("Error: Numero de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }
    printf("a");
    CheckParameters(argv);
    printf("Nombre: %s\n", pipeRecibe);
    printf("Peta?");

    if (mkfifo (pipeRecibe, fifo_mode) == -1) {
        perror("Server mkfifo:");
        exit(1);
    }

    if ((fd = open (pipeRecibe, O_RDONLY)) == -1) {
        perror(" Servidor abriendo el pipe: ");
        exit(1);
    }

    printf("crea hilos");
    if (pthread_create(&hilo_pipes, NULL, crear_pipes_thread, NULL) != 0) {
        perror("Error al crear el hilo de pipes");
        exit(EXIT_FAILURE);
    }

    printf("crea hilos2");
    // Crea el primer hilo para realizar el conteo
    if (pthread_create(&hilo_conteo, NULL, conteo_thread, NULL) != 0) {
        perror("Error al crear el hilo de conteo");
        exit(EXIT_FAILURE);
    }

    printf("peta");
    // Espera a que ambos hilos terminen
    error1 = pthread_join(hilo_pipes, (void **)&salida);
    if (error1){
        fprintf (stderr, "Error: %d: %s\n", error1, strerror (error1));
        exit(-1);
    }
    error2 = pthread_join(hilo_conteo, (void **)&salida);
    if (error2){
        fprintf (stderr, "Error: %d: %s\n", error2, strerror (error2));
        exit(-1);
    }
    pthread_exit(NULL);

    printf("Ambos hilos han terminado. Fin del programa.\n");

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
    if(parameters[1][1] == 'i'){
        horaInicio = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 'f'){
        horaFinal = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 's'){
        segundosHora = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 't'){
        totalPersonas = atoi(parameters[2]);
    }
    else if(parameters[1][1] == 'p'){
        strcpy(pipeRecibe, parameters[2]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[3][1] == 'i'){
        horaInicio = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 'f'){
        horaFinal = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 's'){
        segundosHora = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 't'){
        totalPersonas = atoi(parameters[4]);
    }
    else if(parameters[3][1] == 'p'){
        strcpy(pipeRecibe, parameters[4]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[5][1] == 'i'){
        horaInicio = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 'f'){
        horaFinal = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 's'){
        segundosHora = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 't'){
        totalPersonas = atoi(parameters[6]);
    }
    else if(parameters[5][1] == 'p'){
        strcpy(pipeRecibe, parameters[6]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[7][1] == 'i'){
        horaInicio = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 'f'){
        horaFinal = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 's'){
        segundosHora = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 't'){
        totalPersonas = atoi(parameters[8]);
    }
    else if(parameters[7][1] == 'p'){
        strcpy(pipeRecibe, parameters[8]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }

    if(parameters[9][1] == 'i'){
        horaInicio = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'f'){
        horaFinal = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 's'){
        segundosHora = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 't'){
        totalPersonas = atoi(parameters[10]);
    }
    else if(parameters[9][1] == 'p'){
        strcpy(pipeRecibe, parameters[10]);
    }
    else{
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        exit(1);
    }

    if(horaInicio < 7 || horaInicio > 19){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        printf("Adicionalmente el parque está abierto desde las 7 hasta las 19 horas por lo tanto el tiempo de inicio debe encontrarse entre ese intervalo \n");
        exit(1);
    }

    if(horaFinal < 7 || horaFinal > 19){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        printf("Adicionalmente el parque está abierto desde las 7 hasta las 19 horas por lo tanto el tiempo de finalización debe encontrarse entre ese intervalo \n");
        exit(1);
    }

    if(horaFinal < horaInicio){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        printf("Adicionalmente la hora de finalización del parque debe ser mayor a la hora de inicio del parque \n");
        exit(1);
    }

    if(totalPersonas <= 0){
        printf("Error: Argumento inválido. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./controlador -i [horaInicio] -f [horafinal] -s [segundoshora] -t [totalpersonas] -p [piperecibe]\n");
        printf("Adicionalmente la cantidad de personas maximas en el parque debe ser mayor a 0 \n");
        exit(1);
    }
}