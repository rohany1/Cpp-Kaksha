#include<iostream>
using namespace std;

int countPathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    int count=0;
    count+=countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
    return count;
    
}
int main(){
    cout<<countPathMaze(3,0,0);
    return 0;
}