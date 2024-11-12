#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root){
    stack<Node*> s;
   Node* curr = root;
   while(curr!=NULL || !s.empty()){
    while(curr!=NULL){
        s.push(curr);
        curr = curr->left;
    }
    curr = s.top();
    s.pop();
    cout<<curr->data<<" ";
    
    curr = curr->right;
   }
}


int main(){
    Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 18);

   inorder(root);
}