#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int N=1e6+2;
    bool b[N];
    for(int i=0;i<N;i++){
        b[i]=false;
    }

    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            b[arr[i]]=true;
        }
    }
    for(int i=1;i<N;i++){
        if(b[i]==false){
            cout<<i<<endl;
            break;
        }
    }
}