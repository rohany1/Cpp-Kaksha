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

//check whether tree is bst or not
bool checkBST(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftCheck=checkBST(root->left,min,root);
    bool rightCheck=checkBST(root->right,root,max);
    return leftCheck && rightCheck;

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
    Node* root=new Node(8);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(5);
    root->left->right->left=new Node(3);
    root->left->right->right=new Node(7);
    root->right=new Node(9);
    root->right->right=new Node(10);

    if(checkBST(root,NULL,NULL)){
        cout<<"Valid BST";
    }else{
        cout<<"Invalid BST";
    }
}