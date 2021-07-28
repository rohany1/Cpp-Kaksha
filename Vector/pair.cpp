#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myComparator(pair<int,int> p1, pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(),myComparator);
    // for(int i=0;i<n;i++){
    //     cout<<v[i].first<<" ";
    // }cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<v[i].second<<" ";
    // }cout<<endl;

    for(int i=0;i<n;i++){
        arr[v[i].second]=i;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}