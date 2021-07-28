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

    int currSum[n+1];
    currSum[0]=0;
    for(int i=1;i<=n;i++){
        currSum[i]=currSum[i-1]+arr[i-1];
    }
    
    //Print the arrays
    // for(int i=0;i<n+1;i++){
    //     cout<<currSum[i]<<" ";
    // }cout<<endl;

    int maxSum=INT_MIN;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum=currSum[i]-currSum[j];
            maxSum=max(sum,maxSum);
        }
    }
    cout<<maxSum<<endl;

}