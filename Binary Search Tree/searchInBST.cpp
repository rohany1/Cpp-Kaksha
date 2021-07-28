#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insertBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        //val>root->data
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

Node* searchInBST(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(key<root->data){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

int main(){
    Node* root=NULL;
    root=insertBST(root,4);
    insertBST(root,2);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,6);
    inorderPrint(root);
    cout<<endl;
    if(searchInBST(root,5)==NULL){
        cout<<"Key Not Found";
    }else{
        cout<<"Key Found";
    }
}