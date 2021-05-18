#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);

int año = (1900 + ltm->tm_year)*10000;
int mes = (1 + ltm->tm_mon)*100;
int dia = ltm->tm_mday;

const int MAX_LETRAS = 50;
const int MAX_PRODUCTOS = 100;

string temp;
int contador;
int dineroAct = 0;

FILE *bodega;
FILE *caja;

struct Inventario{
    int codigoInventario;
    char nombreProducto[MAX_LETRAS];
    int cantidadBodega;
    float precioCompra;
    float precioVenta;
};

struct Transacciones{
    int fecha;
    int codigoInventario;
    char compraVenta;
    int cantidadTransaccion;
    int costo;
    int saldoCaja;
};

void agregar(struct Inventario producto);
void modificar(struct Inventario producto);
void infoProd(struct Inventario producto);
void vender(struct Inventario producto, struct Transacciones objeto);
void comprar(struct Inventario producto, struct Transacciones objeto);
void ultTransacciones(struct Transacciones objeto);

int main(){
    Inventario producto;
    Transacciones objeto;
    int cant_Product = 0;
    int opcion;
    contador=0;

    bodega = fopen("bodega.txt", "r+");
    if(bodega == NULL){
        bodega = fopen("bodega.txt", "w");
        fclose(bodega);
        bodega = fopen("bodega.txt", "r+");
        producto.codigoInventario = contador;
        temp = "Inicio";
        strcpy(producto.nombreProducto,temp.c_str());
        producto.cantidadBodega = 1;
        producto.precioCompra = 1;
        producto.precioVenta = 1;
        fwrite(&producto,sizeof(producto),1,bodega);
    }
    fread(&producto,sizeof(producto),1,bodega);
    while(! feof(bodega)){
        fread(&producto,sizeof(producto),1,bodega);
    }
    contador = producto.codigoInventario;
    contador++;

    caja = fopen("caja.txt", "r+");
    if(caja == NULL){
        caja = fopen("caja.txt", "w");
        fclose(caja);
        caja = fopen("caja.txt", "r+");
        objeto.fecha = 0;
        objeto.codigoInventario = 0;
        objeto.compraVenta = 'C';
        objeto.cantidadTransaccion = 0;
        objeto.costo = 0;
        objeto.saldoCaja = 0;
        fwrite(&objeto,sizeof(objeto),1,caja);
    }
    fread(&objeto,sizeof(objeto),1,caja);
    while(!feof(caja)){
        fread(&objeto,sizeof(objeto),1,caja);
    }
    dineroAct = objeto.saldoCaja;

    cout << "Ingrese que operacion desea realizar: 1) Agregar producto, 2) modificar producto, 3) Ver informacion del producto, 4) Vender un producto, 5) surtir un producto, 6) Ultimos movimientos, 7) salir:\n";
    cin >> opcion;
    while(opcion < 1 || opcion > 7){
        cout << "Ingrese una opcion del 1 al 7: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            agregar(producto);
            break;
        case 2:
            modificar(producto);
            break;
        case 3:
            infoProd(producto);
            break;
        case 4:
            vender(producto, objeto);
            break;
        case 5:
            comprar(producto, objeto);
            break;
        case 6:
            ultTransacciones(objeto);
            break;
        default:
            cout << "\n";
            break;
    }
    fclose(bodega);
    fclose(caja);
    return 0;
}

void agregar(struct Inventario producto){
    if(contador > MAX_PRODUCTOS){
        cout << "Ya tiene todos los espacios de productos ocupados";
    }
    else{
        cout << "Ingrese el nombre del producto: ";
        getline(cin>>ws,temp);
        strcpy(producto.nombreProducto, temp.c_str());
        producto.codigoInventario = contador;
        contador++;
        cout << "Ingrese la cantidad de unidades en bodega: ";
        cin >> producto.cantidadBodega;
        cout << "Ingrese el precio de compra del producto: ";
        cin >> producto.precioCompra;
        cout << "Ingrese el precio de venta del producto: ";
        cin >> producto.precioVenta;
        fwrite(&producto, sizeof(producto), 1, bodega);
        cout << "Producto creado satisfactoriamente\n";
    }
    return;
}

void modificar(struct Inventario producto){
    int modProd, existe = 0, numProd;
    cout << "Ingrese el codigo de inventario del producto que desea modificar: ";
    cin >> modProd;
    while(modProd < 1 || modProd > 100){
        cout << "Ingrese un id entre 1 y 100: ";
        cin >> modProd;
    }
    fread(&producto, sizeof(producto),1,bodega);
    while(!feof(bodega)){
        if(producto.codigoInventario == modProd){
            existe = 1;
            producto.codigoInventario = modProd;
            cout << "Ingrese el nuevo nombre del producto: ";
            getline(cin>>ws,temp);
            strcpy(producto.nombreProducto, temp.c_str());
            cout << "Ingrese la nueva cantidad de unidades: ";
            cin >> producto.cantidadBodega;
            cout << "Ingrese el nuevo precio de compra: ";
            cin >> producto.precioCompra;
            cout << "Ingrese el nuevo precio de venta: ";
            cin >> producto.precioVenta;
            fseek(bodega,ftell(bodega)-sizeof(producto),SEEK_SET);
            fwrite(&producto,sizeof(producto),1,bodega);
            cout << "Producto modificado satisfactoriamente\n";
        }
        fread(&producto, sizeof(producto),1,bodega);
    }
    if(existe==0){
        cout << "El producto aun no existe\n";
    }
    return;
}

void infoProd(struct Inventario producto){
    fclose(bodega);
    bodega = fopen("bodega.txt", "r+");
    fread(&producto,sizeof(producto),1,bodega);
    fread(&producto,sizeof(producto),1,bodega);
    while(!feof(bodega)){
        cout << "Codigo: " << producto.codigoInventario << endl;
        cout << "Nombre: " << producto.nombreProducto << endl;
        cout << "Unidades: " << producto.cantidadBodega << endl;
        cout << "Precio compra: $" << producto.precioCompra << endl;
        cout << "Precio venta: $" << producto.precioVenta << endl;
        cout << "\n";
        fread(&producto,sizeof(producto),1,bodega);
    }
    return;
}

void vender(struct Inventario producto, struct Transacciones objeto){
    int codProd, unid, precio, existe = 0;
    fclose(bodega);
    bodega = fopen("bodega.txt", "r+");
    cout << "Ingrese el codigo del producto a vender: ";
    cin >> codProd;
    while(codProd < 1 || codProd > 100){
        cout << "Ingrese un valor entre 1 y 100: ";
        cin >> codProd;
    }
    fread(&producto,sizeof(producto),1,bodega);
    while(!feof(bodega)){
        if(producto.codigoInventario == codProd){
            existe = 1;
            cout << "\nNombre: " << producto.nombreProducto << endl;
            cout << "Unidades: " << producto.cantidadBodega << endl;
            cout << "Precio venta: $" << producto.precioVenta << "\n\n";
            cout << "Cuantas unidades deseas vender?: ";
            cin >> unid;
            if(unid > producto.cantidadBodega){
                cout << "No hay unidades suficientes para la venta\n";
            }
            else if(unid < 1){
                cout << "No se le puede vender esa cantidad de unidades\n";
            }
            else{
                precio = producto.precioVenta * unid;
                cout << "Precio de venta final: $" << precio << endl;
                producto.cantidadBodega -= unid;
                dineroAct += precio;
                objeto.fecha = año + mes + dia;
                objeto.codigoInventario = producto.codigoInventario;
                objeto.compraVenta = 'V';
                objeto.cantidadTransaccion = unid;
                objeto.costo = precio;
                objeto.saldoCaja = dineroAct;
                fwrite(&objeto,sizeof(objeto),1,caja);
                fseek(bodega,ftell(bodega)-sizeof(producto),SEEK_SET);
                fwrite(&producto,sizeof(producto),1,bodega);
            }
        }
        fread(&producto,sizeof(producto),1,bodega);
    }
    if(existe == 0){
        cout << "El producto no existe\n";
    }
    return;
}

void comprar(struct Inventario producto, struct Transacciones objeto){
    int codProd, unid, precio, existe = 0;
    fclose(bodega);
    bodega = fopen("bodega.txt", "r+");
    cout << "Ingrese el codigo del producto que desea comprar: ";
    cin >> codProd;
    while(codProd < 1 || codProd > 100){
        cout << "Ingrese un valor valido entre 1 y 100: ";
        cin >> codProd;
    }

    fread(&producto,sizeof(producto),1,bodega);
    while(!feof(bodega)){
        if(producto.codigoInventario == codProd){
            existe = 1;
            cout << "\nNombre: " << producto.nombreProducto << endl;
            cout << "Unidades: " << producto.cantidadBodega << endl;
            cout << "Precio Compra: $" << producto.precioCompra << "\n\n";
            cout << "Cuantas unidades desea comprar?: ";
            cin >> unid;
            if(unid < 1){
                cout << "No se puede comprar esa cantidad de productos\n";
            }
            else{
                precio = producto.precioCompra * unid;
                cout << "Precio de compra final: $" << precio << endl;
                if(dineroAct < precio){
                    cout << "No dispone de dinero suficiente para realizar esta compra\n";
                }
                else{
                    producto.cantidadBodega += unid;
                    dineroAct -= precio;
                    objeto.fecha = año + mes + dia;
                    objeto.codigoInventario = producto.codigoInventario;
                    objeto.compraVenta = 'C';
                    objeto.cantidadTransaccion = unid;
                    objeto.costo = precio * -1;
                    objeto.saldoCaja = dineroAct;
                    fwrite(&objeto,sizeof(objeto),1,caja);
                    fseek(bodega,ftell(bodega)-sizeof(producto),SEEK_SET);
                    fwrite(&producto,sizeof(producto),1,bodega);
                }
            }
        }
        fread(&producto,sizeof(producto),1,bodega);
    }
    if(existe == 0){
        cout << "El producto no existe";
    }
    return;
}

void ultTransacciones(struct Transacciones objeto){
    int numTransacciones = 0, transAct = 1;
    fclose(caja);
    caja = fopen("caja.txt", "r+");
    fread(&objeto,sizeof(objeto),1,caja);
    fread(&objeto,sizeof(objeto),1,caja);
    while(!feof(caja)){
        numTransacciones++;
        fread(&objeto,sizeof(objeto),1,caja);
    }
    fclose(caja);
    caja = fopen("caja.txt", "r+");
    fread(&objeto,sizeof(objeto),1,caja);
    fread(&objeto,sizeof(objeto),1,caja);
    if(numTransacciones <= 10){
        while(!feof(caja)){
            cout << "Fecha: " << objeto.fecha << endl;
            cout << "Codigo producto: " << objeto.codigoInventario << endl;
            cout << "Compra o venta: " << objeto.compraVenta << endl;
            cout << "Cantidad comprada/vendida: " << objeto.cantidadTransaccion << endl;
            cout << "Costo: $" << objeto.costo << endl;
            cout << "Saldo Caja: $" << objeto.saldoCaja << "\n\n";
            fread(&objeto,sizeof(objeto),1,caja);
        }
    }
    else{
        while(!feof(caja)){
            if(transAct > numTransacciones - 10){
                cout << "Fecha: " << objeto.fecha << endl;
                cout << "Codigo producto: " << objeto.codigoInventario << endl;
                cout << "Compra o venta: " << objeto.compraVenta << endl;
                cout << "Cantidad comprada/vendida: " << objeto.cantidadTransaccion << endl;
                cout << "Costo: $" << objeto.costo << endl;
                cout << "Saldo caja: $" << objeto.saldoCaja << "\n\n";
                fread(&objeto,sizeof(objeto),1,caja);
            }
        }
    }
    return;
}
