#include<iostream>
using namespace std;

void subSequence(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    } 

    char ch=s[0];
    string rem=s.substr(1);
    int code=ch;
    subSequence(rem,ans);
    subSequence(rem,ans+ch);
    subSequence(rem,ans+ to_string(code));
}
int main(){
    subSequence("AB","");
    return 0;
}