/* Módulo para la lectura de una matriz y calcular si es una matriz sparse*/

/*
Archivo: pdispersa.h
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: variables útiles para cargar y leer la matriz y parametros, y
prototipo de las funciones que manipulan el archivo y los argv.
Fecha última modificación: 11/09/2023
*/

#include <stdio.h>

static int hayFilas = 0, hayColumnas = 0, hayArchivo = 0, hayNProcesos = 0, hayPorcentaje = 0;

static int pid1, pid2, num_filas, num_columnas, num_procesos, aux_numProcesos = 0, total, porcentaje, trabajoProcesos, nPorcentaje, contador = 0;

static char archivo[100];

char *nombreArchivo;
char archivo1[] = "sumaP1.txt", archivo2[] = "sumaP2.txt";

int **matriz;


typedef struct
{
    int fInicial;
    int cInicial;
    int fFinal;
    int cFinal;
}datosProceso;

void cargarDatos(FILE *archivo, int **matriz, int filas, int columnas);
int contarCeros(int **matriz, datosProceso rango, int columnas);
int main(int argc, char *argv[]);
void CheckParameters(char *parameters[]);