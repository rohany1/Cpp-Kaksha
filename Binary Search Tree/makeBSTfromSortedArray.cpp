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
 Node* generateBST(int arr[],int start,int end){
     if(start>end){
         return NULL;
     }
     int mid=start+(end-start)/2;
     Node* root=new Node(arr[mid]);
     root->left=generateBST(arr,start,mid-1);
     root->right=generateBST(arr,mid+1,end);
     return root;
 }
 void inorder(Node* root){
     if(root==NULL){
         return;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
 }
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    Node* root=generateBST(arr,0,8);
    inorder(root);
    return 0;
}