#include<iostream>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    int j=l;
    while(j<r){
        if(arr[j]<pivot){
            i++;
            //swap
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }j++;
    }
    int temp1=arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=temp1;

    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }else{
        return;
    }
}
int main(){
    int arr[7]={7,6,5,4,3,2,1};
    quickSort(arr,0,6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
}