#include<iostream>
#include<queue>
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

void levelorder(Node* root){
    // Node* temp = root;
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }

}

int main(){
    Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 18);

    levelorder(root);

}