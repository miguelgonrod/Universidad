#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero=0, mitad;
    while(numero % 2 == 0 || numero < 3 || numero > 21){
        printf("Ingresa un numero impar entre 3 y 21: ");
        scanf("%d", &numero);
    }
    mitad = numero / 2;
    for(int i = 1; i <= numero;i+=2){
        for(int j = 1; j <= mitad; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
        mitad--;
    }
    mitad+=2;
    for(int i = numero-2; i >= 1; i-=2){
        for(int j = 1; j <= mitad; j++){
            printf(" ");
        }
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
        mitad++;
    }
    return 0;
}
