#include <iostream>
using namespace std;
int main(){
    int num1, num2, res=0;
    cout << "Ingrese el primer y segundo numero separados por un espacio:\n";
    cin >> num1 >> num2;
    cout << "(";
    for(int i = 0; i < num1; i++){
        res+=num2;
        if(i<num1-1){
            cout << num2 << " + ";
        }
        else{
            cout << num2 << ") = " << res << "\n\n";
        }
    }
    res=0;
    cout << "(";
    for(int i=0; i < num2; i++){
        res+=num1;
        if(i<num2-1){
            cout << num1 << " + ";
        }
        else{
            cout << num1 << ") = " << res << endl;
        }
    }
    return 0;
}
