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
//Diameter of Binary tree with time complexity O(n^2)
//As we are calling a function inside the function which have time complexity O(N);
int diameterOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftTreeDiameter=diameterOfTree(root->left);
    int rightTreeDiameter=diameterOfTree(root->right);

    int leftHeight=heightOfTree(root->left);
    int rightHeight=heightOfTree(root->right);
    int currDiameter=leftHeight+rightHeight+1;

    return max(currDiameter,max(leftTreeDiameter,rightTreeDiameter));
}

//Diameter of binary tree with time complexity O(N)
int diameterTree(Node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int leftTreeDiameter=diameterTree(root->left,&lh);
    int rightTreeDiameter=diameterTree(root->right,&rh);

    int currentDiameter=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currentDiameter,max(leftTreeDiameter,rightTreeDiameter));
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
      \                       Diameter of tree= 7
       8
      /
     9      
    */
   //cout<<diameterOfTree(root)<<endl;
   int height=0;
   cout<<diameterTree(root,&height)<<endl;
}