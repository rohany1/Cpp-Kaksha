#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int maxPathSumUtil(Node*root, int &ans){
    if(root==NULL){
        return 0;
    }
    int leftSum=maxPathSumUtil(root->left,ans);
    int rightSum=maxPathSumUtil(root->right,ans);

    int maxSum=max(max(root->data,root->data+leftSum+rightSum),
                    max(root->data+leftSum,root->data+rightSum));
    ans=max(ans,maxSum);
    int singleSum= max(root->data,max(rightSum,leftSum)+root->data);
    return singleSum;
}
int maxPathSum(Node* root){
    
    int ans=INT_MIN;
    ans=maxPathSumUtil(root,ans);
    return ans;
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
    
    cout<<maxPathSum(root)<<endl;
}