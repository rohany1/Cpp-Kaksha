#include<iostream>
using namespace std;

string moveallX(string s){
    if(s.length()==0){
        return "";
    }
    string result=moveallX(s.substr(1));
    if(s[0]=='x'){
        return result+s[0];
    }else{
        return s[0]+result;
    }
}
int main(){
    cout<<moveallX("xxxabxxbjkdkxbf");
    return 0;
}