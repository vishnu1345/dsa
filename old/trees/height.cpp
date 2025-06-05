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

int height(Node* root){
    if(root->left==NULL && root->right==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left , right)+1;
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

    // Calculate the height of the BST
    int treeHeight = height(root);

    // Print the height of the BST
    cout << "Height of the BST: " << treeHeight << endl;

    return 0;
}
