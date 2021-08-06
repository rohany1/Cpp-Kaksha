//heap question as it include smallest and K keywords so we use maxheap 
#include<bits/stdc++.h>
using namespace std;
int kthSmallestnumber(int arr[],int size,int k){
    priority_queue<int>maxH;
    for(int i=0;i<size;i++){
        maxH.push(arr[i]);
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    return maxH.top();
}
int main(){
    int arr[]={7,10,4,3,20,15};
    int size=6;
    int k=3;

    cout<<kthSmallestnumber(arr,size,k)<<endl;
}