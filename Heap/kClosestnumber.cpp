#include<bits/stdc++.h>
using namespace std;

void kClosest(int arr[],int size,int k,int x){
    priority_queue<pair<int,int>>maxH;
    for(int i=0;i<size;i++){
        maxH.push({abs(arr[i]-x),arr[i]});
        if(maxH.size()>k){
            maxH.pop();
        }
    }
    while(!maxH.empty()) {
        cout<<maxH.top().second<<" ";
        maxH.pop();
    }
}
int main(){
    int arr[]={5,6,7,8,9,10,11,12};
    int size=8;
    int k=5;
    int x=9;
    kClosest(arr,size,k,x);
}