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

int mindepth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    // If one child is NULL, we only consider the depth of the other child
    if (root->left == NULL) {
        return mindepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return mindepth(root->left) + 1;
    }

    // If both children are non-NULL, take the minimum depth of both
    return min(mindepth(root->left), mindepth(root->right)) + 1;
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
    int treeHeight = mindepth(root);

    // Print the height of the BST
    cout << "max depth of the BST: " << treeHeight << endl;

    return 0;
}
