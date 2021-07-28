#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* right;
    struct Node* left;

    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;//Which never gonna happen
}
Node* buildTree(int inorder[],int preorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=0;
    int curr=preorder[idx];
    idx++;
   
    Node* n=new Node(curr);
    if(start==end){
        return n;
    }
    int pos=search(inorder,start,end,curr);
    n->left=buildTree(inorder,preorder,start,pos-1);
    n->right=buildTree(inorder,preorder,pos+1,end);
    return n;
}
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
int main(){
    int inorder[]={4 ,2 ,5 ,1 ,6 ,3 ,7};
    int preorder[]={1 ,2 ,4 ,5 ,3 ,6 ,7};
    Node* root=buildTree(inorder,preorder,0,6);
    inorderPrint(root);

}