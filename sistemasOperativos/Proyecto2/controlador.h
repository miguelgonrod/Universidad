/* Módulo para controlar las personas que ingresan a un parque de atracciones*/

/*
Archivo: controlador.h
Realizado por: Miguel Angel Gonzalez Rodriguez
Contiene: variables útiles para controlar las personas, los pipes, parametros, y
prototipo de las funciones que manipulan los argv.
Fecha última modificación: 13/11/2023
*/

static int horaInicio, horaFinal, segundosHora, totalPersonas, horaActual, fd, cuantosExisten = 0, negadas = 0, aceptadas = 0, reprogramadas = 0;
static char pipeRecibe[100];
static int horaPersonas[2][13] = {{7,8,9,10,11,12,13,14,15,16,17,18,19},{0,0,0,0,0,0,0,0,0,0,0,0,0}};

typedef struct {
    char nombre_pipe[50];
    int pipe_fd[2];
} PipeInfo;
PipeInfo pipes[100];

struct InfoSolicitud {
    char nombre[100];
    char nombrePipe[100];
    int inicio;
    int numPersonas;
};

void CheckParameters(char *parameters[]);
int main(int argc, char *argv[]);
