#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "empleados.h"

/* enviarPipe
    envia los primeros cuantos empleados del arreglo al pipe
*/
void EnviarPipe(emple *miemp, int cuantos, int fd) {

  int i, creado;

  // este código lo tienen que hacer Uds. para  enviar los datos. 

  // Enviar los datos de los empleados al pipe
  for (i=0; i < cuantos; i++) {
    creado = write(fd, &miemp[i], sizeof(emple));
    if (creado == -1) {
      perror("write");
      exit(1);
    }
  }

  close(fd);
}

/* asignar
   inserta un nuevo empleado en la lista en la posicion pos
   e inicializa su edad, tiempo de trabajo y nombre
*/
void asignar(emple *emp, char *nombre, int edad, float salary, int pos)
{
     
  char *p;
   
  emp[pos].edad = edad;
  emp[pos].salario = salary;
  strcpy(emp[pos].nombre, nombre);
 
}

/* imprimir
   imprime los primeros cuantos empleados del arreglo
*/
void  imprimir(emple *emp, int cuantos)
{
  int i;

    printf("Empleados:\n");

  for(i=0; i < cuantos; i++)
    printf("%s %d %f\n",  emp[i].nombre, emp[i].edad, emp[i].salario);
}


int main(int argc, char *argv[]) 
{
  emple miemp[MAXEMP];
  char line[MAXLIN], nom[MAXNOMBRE];
  FILE *fp;
  int i, edad=0, fd;
  float salario;
  
  fp = fopen(argv[1], "r");
  i = 0;

  while (!feof(fp))  {
    fscanf(fp, "%s %d %f\n", nom,&edad, &salario);
    /* printf("valid: %s\n", line); */
    /* printf("%d, %d, %s\n", edad, tiempo, nom); */
    asignar(miemp, nom, edad, salario, i++);
  }
  
  imprimir(miemp, i);
 

  // Abrir el pipe 
  
  fd = open (argv[2], O_WRONLY);

  // Enviar los datos de los empleados al pipe
   
  EnviarPipe(miemp,i,fd);
  

     
  fclose(fp); 
}
