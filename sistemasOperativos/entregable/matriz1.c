/* Ejemplo: matriz.c
   Crea el numero de procesos que recibe por argv y cada proceso va a imprimir un cierto numero de filas de la matriz
   

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  if(argc != 2){
    printf("Error: Numero de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
    printf("$ ./matriz [numero de procesos]\n");
    exit(1);
  }
  else if(atoi(argv[1]) < 1 || atoi(argv[1]) == 4 || atoi(argv[1]) == 5 || atoi(argv[1]) > 6){
    printf("Error: El numero de procesos debe ser un divisor de 6 y mayor a 0. (1, 2, 3, 6)\n");
    exit(1);
  }

  int status, i,nprocesos,cuantos, cantFila = 0;
  int matriz[6][6]={{1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,3,3,3,3},{4,4,4,4,4,4},{5,5,5,5,5,5},{6,6,6,6,6,6}};
  pid_t childpid;

  nprocesos = atoi(argv[1]);
  cuantos = 6/nprocesos;

  for (i = 0; i < nprocesos; ++i) { // Creaci�n de los procesos.

    if ((childpid = fork()) < 0) {
      perror("fork:");
      exit(1);
    }
    // colocar aqui el c�digo de los hijos

    if (childpid == 0) {
      printf("Hijo %d\n", i+1);
      int j;
      for (j = i*cuantos; j < (i+1)*cuantos; ++j) {
        int k;
        for (k = 0; k < 6; ++k) {
          cantFila += matriz[j][k];
        }
      }
      printf("El resultado de las filas asignadas es: %d\n\n", cantFila);
      cantFila = 0;
      exit(0);
    }
  }

  // El padre espera por todos los hijos que creo.
  for (i = 0; i < nprocesos; ++i){
    wait(&status);
  }
  printf("El padre termina\n");
  return 0;
}
