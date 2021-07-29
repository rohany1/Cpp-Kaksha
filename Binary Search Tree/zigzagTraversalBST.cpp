#include<iostream>
#include<stack>
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

void printZigZag(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    currLevel.push(root);
    bool leftToRight=false;
    while(currLevel.size()!=0 || nextLevel.size()!=0){
        if(currLevel.size()!=0){
            cout<<currLevel.top()->data<<" ";
            Node* top=currLevel.top();
            if(!leftToRight){
                if(top->left!=NULL){
                    nextLevel.push(top->left);
                }
                if(top->right!=NULL){
                    nextLevel.push(top->right);
                }
            }else{
                if(top->right!=NULL){
                    nextLevel.push(top->right);
                }
                if(top->left!=NULL){
                    nextLevel.push(top->left);
                }
            }
            currLevel.pop();
        }
        else{
            stack<Node*>temp=currLevel;
            currLevel=nextLevel;
            nextLevel=temp;
            if(leftToRight){
                leftToRight=false;
            }else{
                leftToRight=true;
            }
        }
        
    }
    
}

int main(){
    Node* root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->left->right=new Node(8);

    root->left->right=new Node(5);
    root->left->right->left=new Node(9);

    root->right->left=new Node(6);
    root->right->left->right=new Node(10);

    root->right->right=new Node(7);
    root->right->right->right=new Node(11);

    

    /*   1
        / \
       2   3
      / \  / \
     4   5 6  7
      \ /   \  \
      8 9   10  11
    */
   printZigZag(root);
}