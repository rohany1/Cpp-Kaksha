//return all k largest elements in an array
//arr: [7,10,4,3,20,15]
//O/p: [10,15,20]//order not matter
#include<bits/stdc++.h>
using namespace std;

void kLargestElement(int arr[],int size,int k){
    priority_queue<int,vector<int>,greater<int>>minH;
    for(int i=0;i<size;i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            minH.pop();
        }
    }
    while(!minH.empty()){
        cout<<minH.top()<<" ";
        minH.pop();
    }
}
int main(){
    int arr[]={7,10,4,3,20,15};
    int size=6;
    int k=4;

    kLargestElement(arr,size,k);
}