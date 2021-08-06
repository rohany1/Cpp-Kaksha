//The coorect place of element at position lie in range of [i-k,i+k] 
//It means you have to sort elements of k size at a time not all elements
#include<bits/stdc++.h>
using namespace std;
vector<int> sortKsortedArray(int arr[],int size,int k){
    priority_queue<int,vector<int>,greater<int>>minH;
    vector<int>ans;
    for(int i=0;i<size;i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            ans.push_back(minH.top());
            minH.pop();
        }
    }
    while(!minH.empty()){
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}
int main(){
    int arr[]={6,5,3,2,8,10,9};
    int size=7;
    int k=3;
    vector<int>result=sortKsortedArray(arr,size,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}