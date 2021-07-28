#include<iostream>
#include<stack>
using namespace std;
//If u make any changes in stack then call it by reference
void reverseStack(stack<int> &st){
    if(st.size()==1){
        return;
    }
    int topElement=st.top();
    st.pop();
    reverseStack(st);
    stack<int> callByStack;
    while(!st.empty()){
        callByStack.push(st.top());
        st.pop();
    }
    st.push(topElement);
    while(!callByStack.empty()){
        st.push(callByStack.top());
        callByStack.pop();
    }
}
int main(){
    stack<int> st;
    for(int i=1;i<=5;i++){
        st.push(i);
    }
    cout<<"Before reverse"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    for(int i=1;i<=5;i++){
        st.push(i);
    }
    reverseStack(st);
    cout<<"After reverse"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}