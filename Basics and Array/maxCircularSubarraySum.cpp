#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum=max(currSum,maxSum);
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Wrap Sum means we need to go for circular array sum like
    //from last position to first one.
    //Nonwrap sum indicates that simple array maximum sum that
    //we used to do in simple kadanes algorithm.

    int wrapSum;
    int nonWrapSum =kadane(arr,n);

    //Calculate total sum and make negative of all the numbers.
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
        //negative of that number
        arr[i]=-arr[i];
    }
    //deduct the non contributing number form total sum.
    wrapSum=totalSum-(-kadane(arr,n));

    cout<<max(wrapSum,nonWrapSum)<<endl;

}