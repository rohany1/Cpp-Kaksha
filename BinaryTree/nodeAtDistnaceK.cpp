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

void printSubtreeNodes(Node* root, int k){
    if(root==NULL){
        return; 
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}
//Return type int because we are returning distance to ancestors
int distanceKNodes(Node* root,int target,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==target){
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl=distanceKNodes(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }else{
            printSubtreeNodes(root,k-dl-2);
        }
        return dl+1;
    }
    int dr=distanceKNodes(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
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

    distanceKNodes(root,6,3);

}