/* Módulo para la lectura de una matriz y calcular si es una matriz sparse*/

/*
Archivo: hdispersa.h
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: variables útiles para cargar y leer la matriz y parametros, y
prototipo de las funciones que manipulan el archivo y los argv.
Fecha última modificación: 25/09/2023
*/

static int num_filas, num_columnas, num_hilos, porcentaje;
static char archivo[100];

struct InfoHilos {
    int inicio;
    int final;
    int **matriz;
    int columnas;
    int *contador;
};

void *buscarUno(void *arg);
void CheckParameters(char *parameters[]);
int main(int argc, char *argv[]);
