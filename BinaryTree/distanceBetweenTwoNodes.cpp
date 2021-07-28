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

Node* lca(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA=lca(root->left,n1,n2);
    Node* rightLCA=lca(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    if(leftLCA!=NULL){
        return root->left;
    }
    return root->right;
}
int findDist(Node* root, int key, int dist){
    if(root==NULL){ 
        return -1;
    }
    if(root->data==key){
        return dist;
    }
    int left=findDist(root->left,key,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,key,dist+1);
}
int distance(Node* root, int n1,int n2){
    if(root==NULL){
        return -1;
    }
    Node* lcancestor=lca(root,n1,n2);
    int distleft=findDist(root,n1,0);
    int distright=findDist(root,n2,0);

    return distleft+distright;
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

    int result=distance(root,4,6);
    cout<<"Distance is: "<<result<<endl;
}