#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Node* &root , int d){
    if(root==NULL){
        root = new Node(d);
        return ;
    }
    else{
        Node* temp = root;
        Node* parent = NULL;
        while(temp!=NULL){
            parent = temp;
            if(temp->data>d){
                temp = temp->left;
            }
            else if(temp->data<d){
                temp = temp->right;
            }
            else return;
        }

        if(parent->data>d){
            parent->left = new Node(d);
        }
        else parent->right = new Node(d);
    }
}


bool isBST(Node* root , int min , int max){
    if(root==NULL){
        return true;
    }

    if(root->data<min || root->data>max){
        return false;
    }

    bool left = isBST(root->left , min , root->data);
    bool right = isBST(root->right , root->data , max);

    return left && right;
}

int main() {
    Node* root = NULL; // Initialize an empty tree

    // Insert nodes into the binary tree
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);

    // Check if the binary tree is a BST
    if (isBST(root, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree" << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree" << endl;
    }

    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(15);
    root2->left->left = new Node(20); // This violates the BST property

    cout << "Tree 2: ";
    if (isBST(root2, INT_MIN, INT_MAX)) {
        cout << "The tree is a Binary Search Tree" << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree" << endl;
    }


    return 0;
}
