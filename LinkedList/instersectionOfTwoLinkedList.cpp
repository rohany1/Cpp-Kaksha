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
void intersectLinkedList(node* &head1,node* &head2,int pos){
    node *tail2=head2;
    while(tail2->next!=NULL){
        tail2=tail2->next;
    }
    node* temp=head1;
    while(pos-1){
        pos--;
        temp=temp->next;
    }
    tail2->next=temp;
}
int intersectNode(node* head1,node* head2){
    int l1=lengthOfLinkedList(head1);
    int l2=lengthOfLinkedList(head2);
    node* ptr1;
    node* ptr2;
    int d;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
int main(){
    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head1,7);
    node* head2=NULL;
    insertAtTail(head2,9);
    insertAtTail(head2,10);
    insertAtTail(head2,11);
    intersectLinkedList(head1,head2,4);
    display(head1);
    display(head2);
    cout<<intersectNode(head1,head2)<<endl;
    return 0;
}