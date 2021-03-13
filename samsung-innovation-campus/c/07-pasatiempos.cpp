#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *hobbies=fopen("pasatiempos.txt","r");
    char basura[3][200];
    char nombres[3][200];
    char pasatiempos[3][200];
    char edades[3][200];
    int edadesNum[3];
    int contador=0;
    int prom = 0;
    fscanf(hobbies, "%s %s %s", basura[0], basura[1], basura[2]);
    while(1){
        fscanf(hobbies, "%s", nombres[contador]);
        fscanf(hobbies, "%s", edades[contador]);
        fscanf(hobbies, "%s", pasatiempos[contador]);
        contador++;
        if(feof(hobbies)) break;
    }
    edadesNum[0]=atoi(edades[0]);
    edadesNum[1]=atoi(edades[1]);
    edadesNum[2]=atoi(edades[2]);
    printf("Nombres: ");
    for(int i = 0; i < contador-1; i++){
        printf("%s, ", nombres[i]);
    }
    printf("\nEdades: ");
    for(int i = 0; i < contador-1; i++){
        printf("%s, ",edades[i]);
        prom+=edadesNum[i];
    }
    printf("\nPasatiempos: ");
    for(int i=0; i < contador-1; i++){
        printf("%s, ",pasatiempos[i]);
    }
    printf("\npromedio: %d", (prom/3));
    return 0;
}
