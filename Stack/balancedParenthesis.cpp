#include<iostream>
#include<stack>
using namespace std;
bool checkBalancedParenthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'||s[i]=='['|| s[i]=='('){
            st.push(s[i]);
        }else{
            if(s[i]=='}' &&  !st.empty() && st.top()=='{'){
                st.pop();
            }else if(s[i]==']' && !st.empty() && st.top()=='['){
                st.pop();
            }else if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s="{[()]}";
    string s1="{[()}]";
    string s2="{[()]}{}[]";
    string s3="{[()]}{}]";
    cout<<checkBalancedParenthesis(s)<<endl;
    cout<<checkBalancedParenthesis(s1)<<endl;
    cout<<checkBalancedParenthesis(s2)<<endl;
    cout<<checkBalancedParenthesis(s3)<<endl;
}