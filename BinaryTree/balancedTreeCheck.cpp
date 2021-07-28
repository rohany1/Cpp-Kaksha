#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
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
bool balanced(Node* root, int *height){
    if(root==NULL){
        *height=0;
        return true;
    }
    int lh=0;
    int rh=0;
    bool leftBalanced=balanced(root->left,&lh);
    bool rightBalanced=balanced(root->right,&rh);
    if(leftBalanced==false){
        return false;
    }
    if(rightBalanced==false){
        return false;
    }

    *height=max(lh,rh)+1;
    if(abs(lh-rh)>1){
        return false;
    }
    else{
        return true;
    }
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
   int height=0;
   cout<<balanced(root,&height)<<endl;
   
}