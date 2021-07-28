//Good question
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int S;
    cin>>S;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int start=-1;
    int end=-1;
    int i=0;
    int j=0;
    int sum=0;
    while(j<n && sum+arr[j]<=S){
        sum+=arr[j];
        j++;
    }
    if(sum==S){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n){
        sum+=arr[j];
        while(sum>S){
            sum-=arr[i];
            i++;
        }
        if(sum==S){
            start=i+1;
            end=j+1;
            break;
        }
        j++;
    }
    cout<<start<<" "<<end<<endl;

    
}