#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftTreeHeight=heightOfTree(root->left);
    int rightTreeHeight=heightOfTree(root->right);
    return max(leftTreeHeight, rightTreeHeight)+1;
}
int main(){
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->right=new Node(8);
    root->left->left->right->left=new Node(9);

    /*   1
        / \
       2   3
      / \  / \
     4   5 6  7               height of Tree= 5
      \
       8
      /
     9    
    */
   cout<<heightOfTree(root)<<endl;
}