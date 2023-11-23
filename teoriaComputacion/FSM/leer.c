
/* archivo leer.c
 * Ejemplo de uso del perror() para validar llamadas al sistema
 *
 * Realizado por Mariela Curiel,  Enero 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char  *argv[]){

  char buffer[5]="hola";
  int a = 7,fd;

  if (argc < 2) {
    printf ("Modo de uso: leer filename \n");
    exit(-1);
  }

  fd = open(argv[1], O_RDWR, S_IRWXU|S_IRWXO);
  if (fd == -1){
    perror("Error: ");
    return -1;
  }

  write (fd, buffer, sizeof(buffer));

  close(fd);



}



