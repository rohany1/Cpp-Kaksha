#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
void leftView(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout<<root->data<<" ";
    q.push(NULL);
    while(!q.empty()){
        Node* n=q.front();
        q.pop();
        if(n!=NULL){
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }else if(!q.empty()){
            cout<<q.front()->data<<" ";
            q.push(NULL);
        }
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
     4   5 6  7
      \
       8
      /
     9
    */
    leftView(root);
    return 0;
}