#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIL 4
#define COL 4
#define NUM_THREADS 4

int matriz[FIL][COL] = {{1,2,1,1},{2,0,0,0},{3,0,0,0},{0,0,0,10}};

// Cada hilo recibe como parámetro la fila con la que va a trabajar
void *sumar(void *fila){

  int sum, fil, i;
  fil  = *((int *)fila);
  sum = 0;

   for (i = 0; i < COL; i++)
     sum += matriz[fil][i];
   printf("El hilo que sumo fila %d, va a devolver sum = %d\n", fil, sum);

   pthread_exit(NULL);
}

// Cada hilo recibe como parámetro la fila con la que va a trabajar
void *maximo(void *fila){

  int fil  = *((int *)fila);
   int max = 0;
   int i;

   for (i = 0; i < COL; i++)
     if (matriz[fil][i] >= max)
       max = matriz[fil][i];
   printf("El hilo trabajo con la  fila %d, y va a devolver maximo = %d\n", fil, max);

   pthread_exit(NULL);
}

int main(int argc, char *argv[]){

  pthread_t threads[NUM_THREADS]; // arreglo de identificadores
  int tarea_ids[NUM_THREADS]; // arreglo para pasar los parámetros
  int rc, t, opcion, i, error, *salida;


  if (argc < 2) {
    printf("Usage hilos [1/2]\n");
    exit(1);
  }

  else opcion=atoi(argv[1]);


  for(t=0;t<NUM_THREADS;t++){
    tarea_ids[t] = t;
    if (opcion == 1){
      error = pthread_create(&threads[t], NULL, sumar, &tarea_ids[t]);
      // crear los hilos para que invoquen la rutina sumar
    }

    else{
      error = pthread_create(&threads[t], NULL, maximo, &tarea_ids[t]);
      // crear los hilos para que busquen el máximo de cada fila.
    }

    if (error){
      fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
      exit(-1);
    }
  }
  for(t=0;t<NUM_THREADS;t++){
    error = pthread_join(threads[t], (void **)&salida);
    if (error){
      fprintf (stderr, "Error: %d: %s\n", error, strerror (error));
      exit(-1);
    }
    // Aquí el padre espera por todos los hijos
  }

    // Imprimir las sumas o maximos de cada fila, dependiendo de la
    // opcion que introdujo el usuario.


  pthread_exit(NULL);
}
