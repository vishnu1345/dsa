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

    Node* ans = maxiel(root);
    cout<<ans->data<<endl;
    Node* ansm = miniel(root);
    cout<<ansm->data<<endl;

}
