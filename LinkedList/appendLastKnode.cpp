#include<iostream>
using namespace std;

class node{
    
    public:
        int data;
        node* next;

        node(int value){
        data=value;
        next=NULL;
    }
    
    
};
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;

}
//Head is taken as a reference not by value
//Because we need to modify our linkedlist.
void insertAtTail(node* &head,int val){
        node* n=new node(val);
        if(head==NULL){
            head=n;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
}
int lengthOfLinkedList(node*head){
    if(head==NULL){
        return 0;
    }
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void append(node* &head,int k){
    int length=lengthOfLinkedList(head);
    int count=1;
    node* temp=head;
    node* newTail;
    node* newHead;
    while(temp->next!=NULL){
        if(count==length-k){
            newTail=temp;
        }
        count++;
        temp=temp->next;
    }
    newHead=newTail->next;
    temp->next=head;
    newTail->next=NULL;
    head=newHead;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    display(head);
    append(head,3);
    display(head);
    return 0;
}