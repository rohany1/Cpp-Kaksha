#include<iostream>
using namespace std;
//Get bit return the value at that position
int getBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}
//Set bit set value 1 to that position
int setBit(int n,int pos){
    return (n | (1<<pos));
}
//clear bit set value to 0 at that position
int clearBit(int n,int pos){
    //mask will make 0 to that postion and 1 to other
    int mask= ~(1<<pos);
    return (n & mask);
}
//Update the particular value to the position
int updateBit(int n,int pos,int value){
    //First we clear that bit position and then set the value
    int mask= ~(1<<pos);
    n=n & mask;
    return (n |(value<<pos));
}
int main(){
    cout<<"GetBit- 5,2= "<<getBit(5,2)<<endl;
    cout<<"SetBit- 5,1= "<<setBit(5,1)<<endl;
    cout<<"ClearBit- 6,1= "<<clearBit(6,1)<<endl;
    cout<<"UpdateBit- 15,2,0= "<<updateBit(15,2,0)<<endl;
    return 0;
}