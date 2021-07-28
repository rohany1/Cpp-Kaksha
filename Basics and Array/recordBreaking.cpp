//Question from lecture 8.4
//Google Kick start
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    int ans=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            if(arr[i]>max)
                ans++;
                break;
        }
        if(arr[i]>max && arr[i]>arr[i+1]){
            ans++;
            max=arr[i];
        }
    }
    cout<<ans;
}