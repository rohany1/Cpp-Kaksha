#include<iostream>
using namespace std;

void increment(int *a){
    ++*a;
}
int main(){
    int a;
    a=10;

    increment(&a);
    cout<<a<<endl;
}