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

node* mergeLinkedList(node* &head1, node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummyNode=new node(-1);
    node* ptr3=dummyNode;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
    }
    while(ptr1!=NULL){
        ptr2->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummyNode->next;
}
node* mergeRecursive(node* &head1,node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,3);
    insertAtTail(head1,5);
    insertAtTail(head1,7);
    display(head1);
    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,6);
    insertAtTail(head2,8);
    display(head2);
    // node* head3=mergeLinkedList(head1,head2);
    node* head4=mergeRecursive(head1,head2);
    display(head4);
}