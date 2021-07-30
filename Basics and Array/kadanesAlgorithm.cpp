#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int currSum=0;
    // int maxSum=INT_MIN;
    // for(int i=0;i<n;i++){
    //     currSum=currSum+arr[i];
    //     if(currSum<0){
    //         currSum=0;
    //     }
    //     maxSum=max(currSum,maxSum);
    // }
    // cout<<maxSum<<" "<<endl;
    
    int tillNow=arr[0];
    int curr=arr[0];
    for(int i=1;i<n;i++){
        curr=max(arr[i],arr[i]+curr);
        tillNow=max(tillNow,curr);
    }
    cout<<tillNow<<endl;

}