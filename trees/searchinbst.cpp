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

bool search(Node* root , int target){
    if(root==NULL){
        return false;
    }

    if(root->data==target){
        return true;
    }
    else if(root->data<target){
        return search(root->right , target);
    }
    else return search(root->left , target);
   
}

bool search(Node* root , int target){
    Node* temp = root;

    while(temp!=NULL){
        if(temp->data==target){
            return true;
            // break;
        }
        else if(root->data<target){
            temp = temp->right;
        }
        else temp = temp->left;
    }
    return false;
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

    cout<<search(root , 12)<<endl;
    cout<<search(root , 5)<<endl;
    cout<<search(root , 6)<<endl;
    cout<<search(root , 9)<<endl;
}