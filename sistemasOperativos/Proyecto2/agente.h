/* Módulo para controlar las personas que ingresan a un parque de atracciones*/

/*
Archivo: agente.h
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: variables útiles para controlar los pipes, parametros, y
prototipo de las funciones que manipulan los argv y los strings.
Fecha última modificación: 13/11/2023
*/

static char nombre[100], pipeRecibe[100], archivoSolicitudes[100];

static char nombreFamilia[100], estado[100];
int cantPersonas, horaInicio;

static char pipeName[100] = "pipe";

struct InfoSolicitud {
    char nombre[100];
    char nombrePipe[100];
    int inicio;
    int numPersonas;
};

void CheckParameters(char *parameters[]);
void tokenizador(char *linea);
int main(int argc, char *argv[]);