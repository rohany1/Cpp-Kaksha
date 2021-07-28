#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n){
        return NULL;
    }
    Node* root=NULL;

    if(key>min && key<max){
        root= new Node(key);
        *preorderIdx=*preorderIdx+1;

        if(*preorderIdx<n){
            root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    /*
                    8
                   / \
                  2   9
                 / \   \
                1   5   10
                   / \ 
                  3   7   
    */
    int preorder[]={8,2,1,5,3,7,9,10};
    int n=8;
    int preorderIdx=0;
    Node* root=constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    preOrder(root);
    return 0;
}