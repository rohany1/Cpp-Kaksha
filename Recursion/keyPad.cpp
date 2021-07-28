#include<iostream>
using namespace std;

string keyString[]={"","/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string code=keyString[ch-'0'];
    string rem=s.substr(1);

    for(int i=0;i<code.length();i++){
        keypad(rem,ans+code[i]);
    }
}

int main(){
    keypad("79","");            
    return 0;
}