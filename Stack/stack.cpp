#include<iostream>
using namespace std;
#define n 100
class stack{
    public:
    int* arr;
    int top;

    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int value){
        if(top==n-1){
            cout<<"Stack is overflown!"<<endl;
            return;
        }
        top++;
        arr[top]=value;
    }

    void pop(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }
};



int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}