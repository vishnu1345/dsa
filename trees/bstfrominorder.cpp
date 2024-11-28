#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* constructBSTFromInorder(int inorder[] , int start , int end){
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;

    Node* root = new Node(inorder[mid]);

    root->left = constructBSTFromInorder(inorder , start , mid-1);
    root->right = constructBSTFromInorder(inorder , mid+1 , end);

    return root;
}

void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Construct the BST
    Node* root = constructBSTFromInorder(inorder, 0, n - 1);

    // Print the preorder traversal of the BST
    cout << "Preorder Traversal of the constructed BST: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}