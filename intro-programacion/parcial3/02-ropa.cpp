#include <iostream>
using namespace std;

struct Prendas(){
    string nombre;
    int precioVenta;
    int numInsumos;
    int codInsumo;
    int tipoInsumo[20][2];
};

struct Insumos(){
    int codInsumo;
    string nomInsumo;
    string unidad;
    int valorUnidad;
};



int main{
    return 0;
}

string costoso(struct Prendas ropa[20], struct Insumos insumo[20], cantPrendas, cantInsumos){
    int masCaro[cantPrendas][2];
    string verdaderoCaro[2];
    int codMasCaro = 0;
    int precioCaro = 0;
    int insumoAct = 0;
    for(int i = 0; i < cantPrendas; i++){
        masCaro[i][0] = i;
        for(int j = 0; j < ropa.numInsumos; j++){
            insumoAct = ropa.tipoInsumo[j][0];
            for(int k = 0; k < cantInsumos;k++){
                if(insumo[k].codInsumo == insumoAct){
                    masCaro[i][1] = ropa.tipoInsumo[j][1]*insumo[k].valorUnidad;
                }
            }
        }
    }

    for(int i = 0; i < cantPrendas; i++){
        if(masCaro[i][1] > precioCaro){
            precioCaro = masCaro[i][1];
            codMasCaro = i;
        }
    }
    verdaderoCaro[0]=ropa[codMasCaro].nombre;
    verdaderoCaro[1]=precioCaro;
    return verdaderoCaro;
}
