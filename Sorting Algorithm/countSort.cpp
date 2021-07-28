#include<iostream>
#include<algorithm>
using namespace std;

void countSort(int arr[],int n){
    //Find maximum in array
    int k=arr[0];
    for(int i=1;i<n;i++){
        k=max(k,arr[i]);
    } 
    int count[10]={0};
    //Count occurence of each number
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //Update the count array
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int arr[9]={1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}