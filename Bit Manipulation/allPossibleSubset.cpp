#include<iostream>
using namespace std;

void allPossibleSubset(char arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}
int main(){
    char arr[]={'a','b','c','d'};
    allPossibleSubset(arr,4);
}