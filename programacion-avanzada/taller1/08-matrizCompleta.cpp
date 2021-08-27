#include <iostream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    int nums[100][100], min, max;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            nums[i][j] = rand() % 1000 + 1; // recorre toda la matriz ingresando valores aleatorios entre 1 y 1000
            if(i == 0 && j == 0){ // en caso de ser el primer valor tomar como valor inicial para el minimo y el maximo
                min = nums[i][j];
                max = nums[i][j];
            }
            if(nums[i][j] > max){ // en caso de que el nuevo valor sea mayor que en el anterior sustituir el valor mayor
                max = nums[i][j];
            }
            if(nums[i][j] < min){ // en caso de que el nuevo valor sea menor que en el anterior sustituir el valor menor
                min = nums[i][j];
            }
        }
    }
    cout << "Minimo: " << min << "\nMaximo: " << max; // imprime el valor mayor y el valor menor
    return 0;
}
