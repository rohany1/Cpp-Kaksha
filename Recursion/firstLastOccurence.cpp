#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key,int i){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOcc(arr,n,key,i+1);
}
int lastOcc(int arr[],int n,int key,int i){
    if(i==-1){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return lastOcc(arr,n,key,i-1);
}

int main(){
    int arr[8]={1,2,3,4,2,2,3,4};
    int n=8;
    int key=2;
    cout<<firstOcc(arr,n,key,0)<<" "<<lastOcc(arr,n,key,n-1)<<endl;
    return 0;
}