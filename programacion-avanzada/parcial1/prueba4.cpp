#include <iostream>
using namespace std;
int main(){
    int n=7;
    int i,x;
    for(i=1;i<=n;i++){
        cin >> x;
        cout << i << ": " << x << " ";
        if(i%3==0){
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
