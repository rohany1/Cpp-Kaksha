#include<iostream>
#include<string>
using namespace std;

void revStr(string s){
    if(s.length()==0){
        return ;
    }
    string rem=s.substr(1);
    revStr(rem);
    cout<<s[0];

}
int main(){
    revStr("rohan");
    return 0;
}