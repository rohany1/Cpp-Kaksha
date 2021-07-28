#include<iostream>
using namespace std;

int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main(){
    cout<<gcd(48,24)<<endl;
    return 0;
}
//Highest common factor
//Approach
//42-24=18                            //42%24=18
//24-18=6                             //24%18=6
//18-6=12                             //18%6=0
//12-6=6
//6-6=0