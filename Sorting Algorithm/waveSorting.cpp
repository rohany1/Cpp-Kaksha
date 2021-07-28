#include<iostream>
using namespace std;
void waveSort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            int temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    waveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}