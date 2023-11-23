#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define MAXLON 1000

#include <pthread.h>

void *cuenta (void* nombre) {
    int pos, cont= 0, leidos;
    char cadena[MAXLON];
    int fd;
    fd= open (nombre, O_RDONLY);
    while ((leidos= read (fd, cadena, MAXLON))!= 0)
        for (pos= 0; pos < leidos; pos++){
            if ((cadena[pos]== 'a') || (cadena[pos]== 'A')){
                cont++;
            }
        }
        printf ("Fichero %s: %d caracteres 'a' o 'A' encontrados\n", (char*)nombre, cont);
        close (fd);
}

int main (int argc, char *argv[]) {
    if (argc!= 2) {
        printf ("Indica el nombre de un fichero.\n");
        exit(0);
    }
    pthread_t hilo;
    int error = pthread_create(&hilo, NULL, cuenta, argv[1]);
    if (error){
        fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
        exit(-1);
    }

    //cuenta (argv[1]);
    pthread_exit(NULL);
}

