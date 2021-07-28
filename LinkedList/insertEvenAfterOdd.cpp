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
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(even->next!=NULL && odd->next!=NULL){
        odd->next=even->next;
        odd=even->next;
        if (odd->next != NULL)
        {
            even->next = odd->next;
            even = even->next;
        }
    }
    odd->next=evenStart;
    even->next=NULL;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);
}