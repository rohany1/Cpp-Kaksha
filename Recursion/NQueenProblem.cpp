#include<iostream>
using namespace std;

bool isSafe(int **arr,int x,int y,int n){
    if(x>=n && y>=n){
        return false;
    }
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    int row=x;int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--,col--;
    }
    row=x;col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--,col++;
    }
    return true;
}

bool NQueenProblem(int **arr,int n,int x){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if(NQueenProblem(arr,n,x+1)){
                return true;
            }
            arr[x][col]=0; //backtracking
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int **arr=new int* [n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    if(NQueenProblem(arr,n,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}