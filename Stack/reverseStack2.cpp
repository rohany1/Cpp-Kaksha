#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int topEle=st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(topEle);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int topElement =st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,topElement);

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
    reverse(st);
    cout<<"After reverse"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}