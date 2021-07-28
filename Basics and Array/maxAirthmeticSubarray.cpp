//Lecture 8.4 for reference of question
//question from google kickstart
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=2;
    //Previous Difference
    int pd=arr[0]-arr[1];
    int j=2;
    int curr=2;
    while(j<n){
        if(pd==arr[j-1]-arr[j]){
            curr++;
        }else{
            pd=arr[j-1]-arr[j];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
    }
    cout<<ans;
}