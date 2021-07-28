#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
int levelKSum(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    int level=0;
    int sum=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k){
                sum+=n->data;
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }

    }
    return sum;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<levelKSum(root,2);
}