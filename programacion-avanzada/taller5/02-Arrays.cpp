#include <iostream>
#include <time.h>

using namespace std;

double* vectorAleatorio();
void momentum();

int main(){
    srand(time(NULL));
    double *ptr = new double;
    momentum();
    delete[] ptr;
    return 0;
}

double* vectorAleatorio(){
    double *ptr = new double[3];
    for(int i=0;i<3;i++){
        ptr[i] = rand() % 201 - 100;
    }
    return ptr;
}

void momentum(){
    int pasos=0;
    double *ptr1 = new double[3000];
    double *ptr2 = new double;
    double *masa = new double[1];
    double *mom = new double[3];
    masa[0] = rand() % 10 + 1;
    for(int i = 0; i<3; i++){
        mom[i]=0;
    }
    for(int i = 0; i < 1000; i++){
        ptr2=vectorAleatorio();
        ptr1[pasos]=ptr2[0];
        pasos++;
        ptr1[pasos]=ptr2[1];
        pasos++;
        ptr1[pasos]=ptr2[2];
        pasos++;
    }
    for(int i = 0; i < 3000; i++){
        ptr1[i]*=masa[0];
    }
    pasos=0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 3; j++){
            mom[j]+=ptr1[pasos];
            pasos++;
        }
    }
    for(int i = 0; i < 3; i++){
        mom[i]=mom[i]/1000;
    }
    cout << "Momentum promedio 1: " << mom[0] << "\nMomentum promedio 2: " << mom[1] << "\nMomentum promedio 3: " << mom[2];
    
    return;
}
