#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ahorcado(int intentos);

char ahorcadoGraf[6][200]={{"\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n     |\n      |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n     |\n  |   |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n     |\n /|\\  |\n      |\n      |\n =========\n"},
    {"\n  +---+\n  |   |\n     |\n /|\\  |\n /    |\n =========\n"},
    {"\n  +---+\n  |   |\n  ﮙ   |\n /|\\  |\n / \\  |\n =========\n"}};

char bienvenida[7][200]={{"+-------------------+"},
                         {"|*******************|"},
                         {"|***** ADIVINA *****|"},
                         {"|******** LA *******|"},
                         {"|***** PALABRA *****|"},
                         {"|*******************|"},
                         {"+-------------------+"}};

char perdedor[6][200]={{"+-----------+"},
                       {"|***********|"},
                       {"|*** HAS ***|"},
                       {"|* PERDIDO *|"},
                       {"|***********|"},
                       {"+-----------+"}};

char ganador[6][200]={{"+------------+"},
                      {"|************|"},
                      {"|***  HAS ***|"},
                      {"|** GANADO **|"},
                      {"|************|"},
                      {"+------------+"}};


int main(){
    while(true){
        int intentos=5;
        int letrasAdivinadas = 0;
        char palabra[100];
        char letra[1];
        char letras[100]= {};
        int contador = 0;
        char adivinado[100];
        int len;
        bool hayPalabra = false;
        printf("Ingresa la palabra a adivinar: \n");
        scanf("%s", palabra);
        getchar();
        len=strlen(palabra);
        system("clear");
        for(int i = 0; i <= len-1; i++){
            adivinado[i]='-';
        }
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",bienvenida[0],bienvenida[1],bienvenida[2],bienvenida[3],bienvenida[4],bienvenida[5],bienvenida[6]);
        while(intentos>0 && letrasAdivinadas!=len){
            ahorcado(intentos);
            printf("Palabra Oculta: %s \n", adivinado);
            printf("Intentos Restantes: %d \n", intentos);
            printf("Letras usadas: ");
            for(int i = 0; i < strlen(letras); i++){
                printf("%c ", letras[i]);
            }
            printf("\nIntroduzca una letra: ");
            scanf("%c", &letra);
            getchar();
            letras[contador] = letra[0];
            contador++;
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
            printf("\nFelicitaciones, has adivinado la palabra\n");
            printf("%s\n%s\n%s\n%s\n%s\n%s\n", ganador[0],ganador[1],ganador[2],ganador[3],ganador[4],ganador[5]);
        }
        else if(intentos==0){
            printf("Incorrecto\n");
            ahorcado(intentos);
            printf("La palabra era ");
            for(int i=0;i < strlen(palabra);i++){
                printf("%c", palabra[i]);
            }
            printf("\n");
            printf("%s\n%s\n%s\n%s\n%s\n%s\n", perdedor[0],perdedor[1],perdedor[2],perdedor[3],perdedor[4],perdedor[5]);
        }
        printf("Deseas jugar de nuevo? (s/n)\n");
        char otravez = 's';
        scanf("%c", &otravez);
        getchar();
        if(otravez == 'n'){
            break;
        }
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
