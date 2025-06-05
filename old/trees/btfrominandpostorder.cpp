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

int findindex(int inorder[] , int val , int n ){
    for(int i=0;i<n;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* solve(int inorder[] , int preorder[] , int &i , int instart , int inend , int n){
    if(i<0 || instart>inend){
        return NULL;
    }
     int el = preorder[i];
     i--;
   Node* root = new Node(el);

    int pos = findindex(inorder , el , n);
    root->right = solve(inorder , preorder  , i , pos+1 , inend , n );
    root->left = solve(inorder , preorder , i , instart , pos-1 , n);

    return root;
}


void inorderTraversal(Node* root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int preorder[] = {3, 9, 20, 15, 7};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    int i = n - 1;
    Node* root = solve(inorder, preorder, i, 0, n - 1, n);

    cout << "Inorder Traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}