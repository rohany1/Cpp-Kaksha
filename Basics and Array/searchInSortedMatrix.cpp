#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    int m1[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>m1[i][j];
        }
    }
    int target;
    cin>>target;

    bool flag=false;
    int r=0, c=n-1;
    
    while(r<m and c>=0){
        cout<<m1[r][c]<<" "<<r<<" "<<c<<endl;
        if(m1[r][c]==target){
            flag=true;
            break;
        }
        if(m1[r][c]<target){
            r++;
        }else{
            c--;
        }
    }

    if(flag){
        cout<<r<<" "<<c;
    }else{
        cout<<"not found";
    }
}