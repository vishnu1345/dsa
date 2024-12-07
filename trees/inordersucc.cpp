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


void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* inordersucc(Node* root , int target){
    Node* temp = root;
    Node* succ = NULL;

    while(temp!=NULL){
        if(temp->data<=target){
            temp = temp->right;
        }
        else{
            succ = temp;
            temp = temp->left;
        }
    }

    return succ;
}

int main() {
    Node* root = NULL;

    // Insert elements into the binary search tree
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Perform inorder traversal to display the elements in sorted order
    cout << "Inorder Traversal of the BST: ";
    inorder(root);
    cout << endl;

    // Find the inorder successor of a target node
    int target = 20;
    Node* successor = inordersucc(root, target);
    if (successor) {
        cout << "Inorder Successor of " << target << " is: " << successor->data << endl;
    } else {
        cout << "Inorder Successor of " << target << " does not exist." << endl;
    }

    return 0;
}
