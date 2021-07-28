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

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//Inorder inorderSuccessor
Node* inorderSuccessor(Node* root){
    Node* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
//Delete in BST
Node* deleteInBST(Node* root,int key){
    //search the key
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }
    //key is found
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        Node* temp=inorderSuccessor(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}
int main(){
    Node* root=new Node(8);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(5);
    root->left->right->left=new Node(3);
    root->left->right->right=new Node(7);
    root->right=new Node(9);
    root->right->right=new Node(10);

    /*
                    8
                   / \
                  2   9
                 / \   \
                1   5   10
                   / \ 
                  3   7   
    */

   inorder(root);
   cout<<endl;
   root=deleteInBST(root,5);
   inorder(root);
}