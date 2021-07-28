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
Node* buildTree(int inorder[],int postorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=6;
    int val=postorder[idx];
    idx--;
    Node* n=new Node(val);
    if(start==end){
        return n;
    }
    int pos=search(inorder,start,end,val);
    n->right=buildTree(inorder,postorder,pos+1,end);
    n->left=buildTree(inorder,postorder,start,pos-1);
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
    int postorder[]={4 ,5 ,2 ,6 ,7 ,3 ,1};
    Node* root=buildTree(inorder,postorder,0,6);
    inorderPrint(root);

}