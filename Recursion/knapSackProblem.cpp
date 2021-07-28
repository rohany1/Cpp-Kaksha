#include<iostream>
using namespace std;

int knapSack(int value[],int weight[],int n,int w){
    if(n==0){
        return 0;
    }
    if(weight[n-1]>w){
        return knapSack(value,weight,n-1,w);
    }
    return max(knapSack(value,weight,n-1,w-weight[n-1])+value[n-1],knapSack(value,weight,n-1,w));
}
int main(){
    int weight[]={10,20,30};
    int value[]={100,50,150};
    int n=3;
    int w=50;
    cout<<knapSack(value,weight,n,w)<<endl;

    return 0;
}