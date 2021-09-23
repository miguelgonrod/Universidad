#include <iostream>
using namespace std;
int main(){
    int n, m=5;
    int a[] = {2,8,3,0,4};
    n = a[0];
    a[0]=a[1]+a[2];
    a[1]++;
    a[n]=m+10;
    a[n+1]=7;
    if(a[0]>=a[7])
        a[4]=a[0];
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4];
    return 0;
}
