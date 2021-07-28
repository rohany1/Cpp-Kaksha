#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int> result;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            result.push(s[i]-'0');
        }
        else{
            int operand1=result.top();
            result.pop();
            int operand2=result.top();
            result.pop();

            switch(s[i]){
                case '+': 
                    result.push(operand1+operand2);
                    break;
                case '-':
                    result.push(operand1-operand2);
                    break;
                case '*':
                    result.push(operand1*operand2);
                    break;
                case '/':
                    result.push(operand1/operand2);
                    break;
                case '^':
                    result.push(pow(operand1,operand2));
                    break;
            }
        }
    }
    return result.top();
}
int main(){
    string prefix="-+7*45+20";
    cout<<prefixEvaluation(prefix)<<endl;
    return 0;
}