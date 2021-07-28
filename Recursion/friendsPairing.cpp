#include<iostream>
using namespace std;
//U can either pair a person or left it alone.
int pairingFriends(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return pairingFriends(n-1)+pairingFriends(n-2)*(n-1);
    //If u left a frined alone so for that call for (n-1)
    //If u want to make pair of a friend than remaining are (n-2)
    //And number of ways u can make its friens are (n-1)
}
int main(){
    cout<<pairingFriends(4)<<endl;
    return 0;
}