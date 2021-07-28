#include<iostream>
using namespace std;

void subsequence(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string rem=s.substr(1);

    subsequence(rem,ans);
    subsequence(rem,ans+ch);
}
int main(){
    subsequence("ABC","");
    return 0;
}