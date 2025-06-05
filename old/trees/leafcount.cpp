#include<iostream>
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


int leafcount(Node* &root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    int l = leafcount(root->left);
    int r = leafcount(root->right);

    return l+r;
}


int main() {
    Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 25);

    // Calculate the number of leaf nodes
    int leafCount = leafcount(root);

    // Print the number of leaf nodes
    cout << "Number of leaf nodes: " << leafCount << endl;

    return 0;
}

