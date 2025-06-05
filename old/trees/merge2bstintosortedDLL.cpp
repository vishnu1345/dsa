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

class DoublyListNode{
    public:
     int val;
    DoublyListNode* prev;
    DoublyListNode* next;

    DoublyListNode(int x) : val(x), prev(NULL), next(NULL) {}
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

DoublyListNode* arraytoLL(vector<int> &arr){
    DoublyListNode* head = new DoublyListNode(arr[0]);
    DoublyListNode* curr = head;

    for(int i=1;i<arr.size();i++){
        DoublyListNode* temp = new DoublyListNode(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

void printDoublyLinkedList(DoublyListNode* head) {
    DoublyListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    // BST 1
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    // BST 2
    root2 = insert(root2, 20);
    root2 = insert(root2, 2);
    root2 = insert(root2, 8);


    // convert to inorder 
    vector<int> arr1;
    convertinorder(root1 , arr1);
    vector<int> arr2;
    convertinorder(root2 , arr2);



    // merge two sorted arrays 
    vector<int> result;

    mergearrays(arr1 , arr2 , result);


    // convert array to doubly Linked list 
    DoublyListNode* head = arraytoLL(result);

    printDoublyLinkedList(head);
}