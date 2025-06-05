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

Node* maxiel(Node* root){
   Node* temp = root;

   
   while(temp->right!=NULL){
    temp = temp->right;
   }

   return temp;
}

Node* miniel(Node* root){
   Node* temp = root;

   
   while(temp->left!=NULL){
    temp = temp->left;
   }

   return temp;
}

bool isBST(Node* root){
    if(root==NULL){
        return true;
    }

   if(root->left!=NULL && (maxiel(root->left)->data>root->data)){
    return false;
   }

   if(root->right!=NULL && (miniel(root->right)->data<root->data)){
    return false;
   }

   return isBST(root->left) && isBST(root->right);
}

int main(){
    Node* root = NULL;

    insert(root , 10);
    insert(root , 11);
    insert(root , 9);
    insert(root , 12);
    insert(root , 13);
    insert(root , 5);

    inorder(root);

    cout<<endl;

    cout<<isBST(root)<<endl;

    Node* nonBSTRoot = new Node(10);
    nonBSTRoot->left = new Node(5);
    nonBSTRoot->right = new Node(15);
    nonBSTRoot->left->right = new Node(12); 

    cout<<isBST(nonBSTRoot)<<endl;
}
