#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int aleatorio = 0, numero, contador = 0;
    while(aleatorio == 0){
        aleatorio = rand() % 101;
    }
    printf("La computadora ha pensado en un numero del 1 al 100, trata de adivinarlo\n");
    while(numero != aleatorio){
        printf("Ingresa un numero: ");
        scanf("%d", &numero);
        if(numero < aleatorio){
            printf("\nEl numero es mayor al ingresado\n");
        }
        else if(numero > aleatorio){
            printf("\nEl numero es menor al ingresado\n");
        }
        contador++;
    }
    printf("Correcto has adivinado el numero en %d intentos", contador);
    return 0;
}
