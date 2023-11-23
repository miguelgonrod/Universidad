#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc == 1){
        printf("Error: número de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./prog Ncadenas cadena1 cadena2 cadena3...cadenaN\n");
        return -1;
    }
    else if (atoi(argv[1]) + 2 != argc){
        printf("Error: número de argumentos inválidos. El programa debe invocarse de la siguiente forma:\n");
        printf("$ ./prog Ncadenas cadena1 cadena2 cadena3...cadenaN\n");
        return -1;
    }

    int contador = 1;

    for(int argumentos = 0; argumentos < argc-2; argumentos++){
        for(int repeticiones = 0; repeticiones < contador; repeticiones++ ){
            printf("%s ", argv[contador+1]);
        }
        printf("\n");
        contador++;
    }
    return 0;
}
