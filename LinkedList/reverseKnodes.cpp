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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseKnodes(node* &head,int k){
    if(head==NULL){
        return head;
    }
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(count<k && currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reverseKnodes(nextptr,k);
    }
    return prevptr;
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
    insertAtTail(head,8);
    //display(head);
    head=reverseKnodes(head,3);
    display(head);

    return 0;
}