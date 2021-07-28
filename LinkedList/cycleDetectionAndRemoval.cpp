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

bool detectCycle(node* head){
    node* fast=head;
    node* slow=head;

    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head,int pos){
    node*temp=head;
    int count=1;
    node*tempPos;
    while(temp->next!=NULL){
        if(count==pos){
            tempPos=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=tempPos;
}
void deleteCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
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
    display(head);
    makeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    // int i=0;
    // node* temp=head;
    // while(i<25){
    //     cout<<temp->data<<"->";
    //     i++;
    //     temp=temp->next;
    // }    
    deleteCycle(head);
    display(head);
    cout<<detectCycle(head)<<endl;
    return 0;
}