#include<bits/stdc++.h>
using namespace std;
int reverse(int a){
    int ans=0;
    while(a>0){
        int lastDigit=a%10;
        ans=ans*10+lastDigit;
        a/=10;
    }
    return ans;
}
int addBinaryNumber(int a,int b){
    int ans=1;
    int carry=0;

    while(a>0 && b>0){
        if(a%2==0 && b%2==0){
            ans=ans*10+carry;
            carry=0;
        }
        else if(a%2==1 && b%2==0 || a%2==0 && b%2==1){
            if(carry==0){
                ans=ans*10+1;
                carry=0;
            }else{
                ans=ans*10;
                carry=1;
            }
        }else{
            ans=ans*10+carry;
            carry=1;
        }
        a=a/10;b=b/10;
    }
    while(a>0){
        if(carry==1){
            if(a%10==1){
                ans=ans*10;
                carry=1;
            }else{
                ans=ans*10+1;
                carry=0;
            }
        }else{
            ans=ans*10+(a%10);
        }
        a=a/10;
    }
    while(b>0){
        if(carry==1){
            if(b%10==1){
                ans=ans*10;
                carry=1;
            }else{
                ans=ans*10+1;
                carry=0;
            }
        }else{
            ans=ans*10+(b%10);
        }
        b/=10;
    }
    if(carry==1){
        ans=ans*10+carry;
    }
    ans=reverse(ans);
    return ans/10;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<addBinaryNumber(a,b)<<endl;
}