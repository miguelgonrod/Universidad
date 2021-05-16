#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int MAX_LETRAS = 50;
const int MAX_PRODUCTOS = 100;

string temp;
int contador;

FILE *bodega;
FILE *caja;

struct Inventario{
    int codigoInventario;
    char nombreProducto[MAX_LETRAS];
    int cantidadBodega;
    float precioCompra;
    float precioVenta;
};

void agregar(struct Inventario producto, struct Inventario comparador);
void modificar();

int main(){
    Inventario producto, comparador;
    int cant_Product = 0;
    int opcion;

    bodega = fopen("bodega.txt", "r+");
    if(bodega == NULL){
        bodega = fopen("bodega.txt", "w");
        fclose(bodega);
        bodega = fopen("bodega.txt", "r+");
    }
    contador = 0;

    caja = fopen("caja.txt", "r+");
    if(caja == NULL){
        caja = fopen("caja.txt", "w");
        fclose(caja);
        caja = fopen("caja.txt", "r+");
    }

    cout << "Ingrese que operacion desea realizar: 1) Agregar producto, 2) modificar producto, 3) Ver informacion del producto, 4) Vender un producto, 5) surtir un producto, 6) Ultimos movimientos, 7) salir:\n";
    cin >> opcion;
    while(opcion < 1 || opcion > 7){
        cout << "Ingrese una opcion del 1 al 7: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            agregar(producto, comparador);
            break;
    }
    fclose(bodega);
    fclose(caja);
    return 0;
}

void agregar(struct Inventario producto, struct Inventario comparador){
    cout << "Ingrese el nombre del producto: ";
    getline(cin>>ws,temp);
    strcpy(comparador.nombreProducto, temp.c_str());
    fread(&producto,sizeof(producto),1,bodega);
    while(!feof(bodega)){
        if(producto.nombreProducto == comparador.nombreProducto){
            cout << "El producto ya existe\n";
            return;
        }
        fread(&producto,sizeof(producto),1,bodega);
    }
    strcpy(producto.nombreProducto, temp.c_str());
    cout << "Ingrese la cantidad de unidades en bodega: ";
    cin >> producto.cantidadBodega;
    cout << "Ingrese el precio de compra del producto: ";
    cin >> producto.precioCompra;
    cout << "Ingrese el precio de venta del producto: ";
    cin >> producto.precioVenta;
    fwrite(&producto, sizeof(producto), 1, bodega);
    cout << "Producto creado satisfactoriamente\n";
    contador++;
    return;
}

/*void modificar(){
    cout << "Ingrese el nombre del producto a modificar: ";
    getline(cin>ws,temp);
    fread(&producto, sizeof(producto),1,bodega);
    while(!feof(bodega)){
        if(bodega.nombre)
    }
}*/
