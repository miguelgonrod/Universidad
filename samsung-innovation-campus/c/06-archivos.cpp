#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f=fopen("sic.html", "w"); // abro un archivo y le asigno la apertura
    fprintf(f, "<h1>GG</h1>\n<p>Hola esta es mi pagina web de samsung innovation campus</p>");
    fclose(f);
    return 0;
}
