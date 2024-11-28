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


void convertinorder(Node* root , vector<int> &in1){
    if(root==NULL){
        return ;
    }

    convertinorder(root->left , in1);
    in1.push_back(root->data);
    convertinorder(root->right , in1);
}

void mergearrays(vector<int> arr1 , vector<int> arr2 , vector<int> &result){
    int i=0;
    int j = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }
        else{
             result.push_back(arr2[j]);
            j++;
        }
    }

    while(i<arr1.size()){
        result.push_back(arr1[i]);
            i++;
    }
    while(j<arr2.size()){
         result.push_back(arr2[j]);
            j++;
    }
}

int main(){
    Node* root1 = new Node(20);
    insert(root1 , 10);
    insert(root1 , 30);
    insert(root1 , 25);
    insert(root1 , 100);

    Node* root2 = new Node(50);
   insert(root2 , 5);
    insert(root2 , 70);
}