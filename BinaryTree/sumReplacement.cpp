#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int sumCalculate(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumCalculate(root->left);
    int rightSum=sumCalculate(root->right);
    int sum=leftSum+rightSum+root->data;
    root->data=sum;
    return sum;
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
   preOrder(root);
   cout<<endl;
   cout<<sumCalculate(root)<<endl;
   preOrder(root);
}