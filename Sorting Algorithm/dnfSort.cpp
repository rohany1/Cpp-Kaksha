#include<iostream>
using namespace std;

void dnfSort(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            int temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
            mid++;low++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            int temp=arr[high];
            arr[high]=arr[mid];
            arr[mid]=temp;
            high--;
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
    dnfSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}