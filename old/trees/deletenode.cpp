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
    q.push(NULL);
    while(!q.empty()){
       Node* front = q.front();
       q.pop();
       if(front == NULL){
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
        
       }
       else {
        cout<<front->data<<" ";
    //    q.pop();
       if(front->left){
            q.push(front->left);
       }

       if(front->right){
        q.push(front->right);
       }
       }
    }

}

Node* minel(Node* root){
   Node* temp = root;

   
   while(temp->left!=NULL){
    temp = temp->left;
   }

   return temp;
}

Node* deleteN(Node* &root , int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data==target){
       
        // no child
        if(root->left==NULL && root->right== NULL){
            delete root;
            return NULL;
        }
        // one child
        else if(root->right==NULL && root->left!=NULL){
                Node* temp = root->left;
                delete root;
                return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            
             Node* temp = root->right;
                delete root;
                return temp;
        }
        //two childs
        else{
           int mini = minel(root->right)->data;
           root->data = mini;
           root->right = deleteN(root->right , mini);
        }
    }
    else if(root->data<target){
        root->right = deleteN(root->right , target);
    }
    else root->left = deleteN(root->left , target);

    return root;
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

    deleteN(root , 18);
    levelorder(root);
    deleteN(root , 7);
    levelorder(root);
    deleteN(root , 10);
    levelorder(root);

}