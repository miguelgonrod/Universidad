#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ahorcado(int intentos);

char ahorcadoGraf[6][200]={{"\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n  0   |\n      |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n  0   |\n  |   |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n  0   |\n /|\\  |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n  0   |\n /|\\  |\n /    |\n =========\n"},
    {"\n  +---+\n  |   |\n  0   |\n /|\\  |\n / \\  |\n =========\n"}};
int main(){
    int intentos=5;
    int letrasAdivinadas = 0;
    char palabra[100];
    char letra[1];
    int len;
    bool hayPalabra = false;
    printf("Ingresa la palabra a adivinar: \n");
    scanf("%s", palabra);
    getchar();
    len=strlen(palabra);
    char adivinado[len];
    system("clear");
    for(int i = 0; i <= len-1; i++){
        adivinado[i]='-';
    }
    while(intentos>0 && letrasAdivinadas!=len){
        ahorcado(intentos);
        printf("Palabra Oculta: %s \n", adivinado);
        printf("Intentos Restantes: %d \n", intentos);
        printf("Introduzca una letra: ");
        scanf("%c", &letra);
        getchar();
        for(int i = 0; i < len; i++){
            if(letra[0]==palabra[i]){
                adivinado[i]=letra[0];
                letrasAdivinadas++;
                hayPalabra = true;
            }
        }
        if(hayPalabra==true && letrasAdivinadas<len){
            printf("Correcto\n\n");
            hayPalabra = false;
        }
        else if(hayPalabra==false && intentos > 1){
            printf("Incorrecto\n\n");
            intentos--;
        }
        else{
            intentos--;
        }
    }
    if(letrasAdivinadas==len){
        printf("\nFelicitaciones, has adivinado la palabra");
    }
    else if(intentos==0){
        printf("Incorrecto has perdido\n");
        ahorcado(intentos);
    }
    return 0;
}

void ahorcado(int intentos){
    if(intentos==5){
        printf("%s", ahorcadoGraf[0]);
    }
    else if(intentos==4){
        printf("%s", ahorcadoGraf[1]);
    }
    else if(intentos==3){
        printf("%s", ahorcadoGraf[2]);
    }
    else if(intentos==2){
        printf("%s", ahorcadoGraf[3]);
    }
    else if(intentos==1){
        printf("%s", ahorcadoGraf[4]);
    }
    else if(intentos==0){
        printf("%s", ahorcadoGraf[5]);
    }
}
