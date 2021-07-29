#include <bits/stdc++.h>
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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root){
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    Info curr;
    Info leftTree=largestBST(root->left);
    Info rightTree=largestBST(root->right);

    curr.size=(leftTree.size+rightTree.size)+1;
    if(leftTree.isBST && rightTree.isBST && root->data>leftTree.max && root->data<rightTree.min){
        curr.min=min(leftTree.min,min(rightTree.min,root->data));
        curr.max=max(rightTree.max,max(leftTree.max,root->data));
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftTree.ans,rightTree.ans);
    curr.isBST=false;
    return curr;
}
int main(){
    Node* root= new Node(5);
    root->left=new Node(2);
    root->right=new Node(6);

    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(7);
    root->right->right=new Node(8);

    /*   5
        / \
       2   6
      / \  / \
     1   3 7  8
    */

   Node* root1=new Node(15);
   root->left=new Node(20);
   root->right=new Node(30);
   root->left->left=new Node(5);
   cout<<"Largest BST size: "<<largestBST(root1).ans<<endl;
   return 0;
}

