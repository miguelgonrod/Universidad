#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void contarLetras(char texto[100],int cantLetras[26], char letras[26]);

int main(){
    char *texto = new char[100];
    int *cantLetras = new int[26];
    char aux1;
    int aux2;
    char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < 26; i++){
        cantLetras[i]=0;
    }
    string temp;
    cout << "Ingrese una cadena de texto:\n";
    getline(cin>>ws,temp);
    strcpy(texto,temp.c_str());
    for(int i = 0; i < 100; i++){
        texto[i]=tolower(texto[i]);
    }
    contarLetras(texto,cantLetras,letras);
    for(int i = 0; i < 26; i++){
        for(int j = 0; j<26-1-i;j++){
            if(cantLetras[j]<cantLetras[j+1]){
                aux2=cantLetras[j];
                cantLetras[j]=cantLetras[j+1];
                cantLetras[j+1]=aux2;
                aux1=letras[j];
                letras[j]=letras[j+1];
                letras[j+1]=aux1;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(cantLetras[i]!=0){
            cout << letras[i] << ": " << cantLetras[i] << endl;
        }
    }
    delete[] texto;
    delete[] cantLetras;
    return 0;
}

void contarLetras(char texto[100],int cantLetras[26], char letras[26]){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 26; j++){
            if(texto[i]==letras[j]){
                cantLetras[j]++;
            }
        }
    }
    return;
}
