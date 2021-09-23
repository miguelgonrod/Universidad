#include <iostream>
using namespace std;

void imprimir(int g);

int main(){
    int x = 3 * 4 + 5;
    imprimir (++x);
    imprimir (x++);
    return 0;
}

void imprimir(int g){
    cout << "El valor es " << g << " ";
}
