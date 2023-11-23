#include <stdio.h>
#include <stdlib.h>

typedef enum{
    DETECTING_OPEN_BRACKET,
    DETECTING_CHARACTERS,
    DETECTING_EMPTY_QUEUE
} APD_states;

int main(int argc, char **argv){
    int coincidencias = 0;
    if(argc != 2){
        printf("Error: Not enough parameters\n");
        printf("Usage: $ ./APDoperations [operation]\n");
        exit(1);
    }
    printf("%s\n", argv[1]);
    APD_states my_apd = DETECTING_OPEN_BRACKET;

    for(int character = 0; argv[1][character] != '\0'; character++){
        switch(my_apd){
            case DETECTING_OPEN_BRACKET:
                if(argv[1][character] != 40 && argv[1][character] != 41){
                    my_apd = DETECTING_OPEN_BRACKET;
                }

                else if(argv[1][character] == 40){
                    coincidencias++;
                    my_apd = DETECTING_CHARACTERS;
                }
                else if(argv[1][character] == 41){
                    coincidencias--;
                    my_apd = DETECTING_EMPTY_QUEUE;
                }
                break;

            case DETECTING_CHARACTERS:
                if(argv[1][character] == 40){
                    coincidencias++;
                    my_apd = DETECTING_CHARACTERS;
                }
                else if(argv[1][character] != 40 && argv[1][character] != 41){
                    my_apd = DETECTING_EMPTY_QUEUE;
                }
                break;

            case DETECTING_EMPTY_QUEUE:
                if(argv[1][character] == 41){
                    coincidencias--;
                    my_apd = DETECTING_EMPTY_QUEUE;
                }
                else if(argv[1][character] == 40){
                    printf("Cadena Invalida\n");
                    exit(1);
                }
                else if(argv[1][character] != 42 && argv[1][character] != 43 && argv[1][character] != 45 && argv[1][character] != 47){
                    my_apd = DETECTING_EMPTY_QUEUE;
                }
                else if(argv[1][character] == 42 || argv[1][character] == 43 || argv[1][character] == 45 || argv[1][character] == 47){
                    my_apd = DETECTING_OPEN_BRACKET;
                }
                break;
        }
        printf("Pila: %d\n", coincidencias);
    }
    if(coincidencias == 0){
        printf("Cadena valida\n");
    }
    else{
        printf("Cadena invalida\n");
    }
    return 0;
}