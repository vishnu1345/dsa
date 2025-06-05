#include<iostream>
#include<stack>
#include<queue>
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

Node* maxel(Node* root){
   Node* temp = root;

   
   while(temp->right!=NULL){
    temp = temp->right;
   }

   return temp;
}

Node* minel(Node* root){
   Node* temp = root;

   
   while(temp->left!=NULL){
    temp = temp->left;
   }

   return temp;
}
void spiralOrderTraversal(Node* root) {
    if (!root) return;

    // Two stacks for alternate level traversal
    stack<Node*> s1; // For left-to-right
    stack<Node*> s2; // For right-to-left

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        // Process nodes in s1 and push children to s2
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Push left child first, then right child
            if (temp->right) s2.push(temp->right);
            if (temp->left) s2.push(temp->left);
        }

        // Process nodes in s2 and push children to s1
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Push right child first, then left child
            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }
    }
}

int main(){
    Node* root = NULL;

    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 18);

    spiralOrderTraversal(root);

}