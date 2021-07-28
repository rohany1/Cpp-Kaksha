#include<iostream>
using namespace std;
int setBit(int n,int pos){
    return (n & (1<<pos))!=0;
}
void unique(int arr[],int n){
    int xorSum=0;
    for(int i=0;i<n;i++){
        xorSum=xorSum^arr[i];
    }
    int tempoXor=xorSum;
    //this xorSum is xor of both unique numbers
    //for example 5 and 7
    //0111^0101=0010
    //on postion 1 only one element among two has set bit(i.e 1)
    //find that position 
    int position=0;
    int setbit=0;
    while(setbit!=1){
        setbit=1 & xorSum;
        position++;
        xorSum=xorSum>>1;
    }
    int newXor=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],(position-1))){
            newXor=newXor^arr[i];
        }
    }
    //We have found the one unique element form this newXor sum
    cout<<newXor<<endl;
    //if we do xor between newXor and xorSum than we get another unique number 
    cout<<(newXor^tempoXor)<<endl;
}
int main(){
    int arr[]={1,2,3,4,8,1,2,3,4,5};
    unique(arr,10);
}