#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "empleados.h" 

int main (int argc, char **argv)
{
    int fd, pid, n, bytes;
    emple em;
  
    mode_t fifo_mode = S_IRUSR | S_IWUSR;
  
    unlink(argv[1]);
    if (mkfifo (argv[1], fifo_mode) == -1) {
        perror("mkfifo");
        exit(1);
    }

  
    fd = open (argv[1], O_RDONLY);

    // Leer los datos de los empleados del pipe
    while ((bytes = read(fd, &em, sizeof(emple))) > 0) {
        // Imprimir los datos del empleado
        printf("%s %d %f\n", em.nombre, em.edad, em.salario);
    }

    // Cerrar el pipe al final de la transmisión
    close(fd);

    return 0;
}





