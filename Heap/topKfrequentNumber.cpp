#include<bits/stdc++.h>
using namespace std;
void topKfrequent(int arr[],int size,int k){
    unordered_map<int,int>mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
    for(auto i=mp.begin();i!=mp.end();i++){
        minH.push({i->second,i->first});
        if(minH.size()>k){
            minH.pop();
        }
    }
    while(!minH.empty()){
        cout<<minH.top().second<<" ";
        minH.pop();
    }
}
int main(){
    int arr[]={1,3,1,2,4,1,2,4,5};
    int size=9;
    int k=3;
    topKfrequent(arr,size,k);
}