#include<iostream>
#include<vector>
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
Node* lca2(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA=lca2(root->left,n1,n2);
    Node* rightLCA=lca2(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    if(leftLCA!=NULL){
        return root->left;
    }
    return root->right;
}
int main(){
    /* 
                 1
                / \
               2   3
              /   / \
             4   5   6
                /
               7
    */
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);
    
    Node* result=lca2(root,7,6);
    if(result==NULL){
        cout<<"LCA does'nt exist";
    }
    else{
        cout<<"LCA : "<<result->data<<endl;
    }
    return 0;
}