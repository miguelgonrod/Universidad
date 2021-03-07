#include <stdio.h>
#include <stdlib.h>
int main(){
    char buffer[50]={0};
    char busqueda[100]={0};
    printf("Ingrese lo que quiere buscar en youtube:\n");
    scanf("%s", busqueda);
    sprintf(buffer, "brave https://www.youtube.com/results?search_query=%s", busqueda);
    system(buffer);
    return 0;
}
