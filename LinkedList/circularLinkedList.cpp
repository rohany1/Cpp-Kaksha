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
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* toDelete=head;
    temp->next=head->next;
    delete toDelete;
    head=temp->next;
}
void deleteNode(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    
}
void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
}
int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deleteNode(head,1);
    deleteNode(head,3);
    display(head);
    return 0;
}