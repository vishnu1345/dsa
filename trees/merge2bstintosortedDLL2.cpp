#include<iostream>
#include<vector>
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


void bsttoDLL(Node* root, Node*& head, Node*& prev) {
    if (root == NULL) {
        return;
    }

    // In-order traversal: Process the left subtree first
    bsttoDLL(root->left, head, prev);

    // Convert the current node
    if (prev == NULL) {
        // This is the first (smallest) node, it becomes the head
        head = root;
    } else {
        // Link the current node with the previous node
        root->left = prev;
        prev->right = root;
    }

    // Update prev to the current node
    prev = root;

    // Process the right subtree
    bsttoDLL(root->right, head, prev);
}

// merge two sorted linked list 



// sorted linked list to bst 
// make middle node as root and recursively solve left and right nodes 
Node* convert(Node* head , Node* end){
    if(head==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast!=end && fast->right!=end){
        slow = slow->right;
        fast = fast->right->right;
    }
    Node* root = new Node(slow->data);
    root->left = convert(head , slow);
    root->right = convert(slow->right , end);

    return root;
}