#include<iostream>
using namespace std;

bool isPowerof2(int n){
    return(n && !(n & n-1));
}
int main(){
    cout<<isPowerof2(256)<<endl;
    cout<<isPowerof2(128)<<endl;
    cout<<isPowerof2(184)<<endl;
}