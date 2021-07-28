#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int> result;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&& s[i]<='9'){
            result.push(s[i]-'0');
        }else{
            int opr2=result.top();
            result.pop();
            int opr1=result.top();
            result.pop();

            switch(s[i]){
                case '+': 
                    result.push(opr1+opr2);
                    break;
                case '-':
                    result.push(opr1-opr2);
                    break;
                case '*':
                    result.push(opr1*opr2);
                    break;
                case '/':
                    result.push(opr1/opr2);
                    break;
                case '^':
                    result.push(pow(opr1,opr2));
                    break;
            }
        }
    }
    return result.top();
}
int main(){
    string postfix="46+2/5*7+";
    cout<<postfixEvaluation(postfix)<<endl;
    return 0;
}
