#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    node* first;
    node* back;

    public:
    queue(){
        first=NULL;
        back=NULL;
    }
    void push(int val){
        node* n=new node(val);
        if(first==NULL){
            back=n;
            first=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(first==NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        node* toDelete=first;
        first=first->next;
        delete toDelete;
    }
    int peek(){
        if(first==NULL){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return first->data;
    }
    bool empty(){
        if(first==NULL){
            return true;
        }
        return false;
    } 
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();
    
    cout<<q.peek()<<endl;
    q.pop();
    
    cout<<q.empty()<<endl;

}