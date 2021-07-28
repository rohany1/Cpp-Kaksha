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
            insertAtHead(head,val);
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
}
bool search(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }return false;
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    node* temp=head;
    if(head->data==val){
        head=head->next;
        delete temp;
        return;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* deleteNode=temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
}
void reverseLinkedList(node* &head){
    if(head==NULL){
        return;
    }
    node* previous=NULL;
    node* current=head;
    node* nextptr;
    while(current!=NULL){
        nextptr=current->next;
        current->next=previous;
        previous=current;
        current=nextptr;
    }
    head=previous;

}
node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,0);
    display(head);
    if(search(head,2)){
        cout<<"Element found"<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    deletion(head,3);
    display(head);
    insertAtTail(head,3);
    deletion(head,0);
    display(head);
    insertAtHead(head,0);
    display(head);
    reverseLinkedList(head);
    display(head);
    head=reverseRecursive(head);
    display(head);
    return 0;
}