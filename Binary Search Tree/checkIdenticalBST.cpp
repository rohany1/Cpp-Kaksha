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

bool identicalBST(Node* root1, Node* root2){
    if(root1 ==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    bool a=(root1->data==root2->data);
    bool b=identicalBST(root1->left,root2->left);
    bool c=identicalBST(root1->right,root2->right);

    if(a && b && c){
        return true;
    }else{
        return false;
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

    /*   1
        / \
       2   3
      / \  / \
     4   5 6  7
    */
   Node* root1= new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);

    root1->left->left=new Node(4);
    root1->left->right=new Node(5);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);

    /*   1
        / \
       2   3
      / \  / \
     4   5 6  7
    */
   if(identicalBST(root,root1)){
       cout<<"Identical BST"<<endl;
   }else{
       cout<<"Different BST"<<endl;
   }
}