#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertHead(Node* &head , int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        newnode->next = head;
        return ;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node* &head , int val){
     Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        newnode->next = head;
        return ;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void insertAfterValue(Node* head, int searchVal, int newVal) {
    Node* temp = head;
    while (temp->next != head && temp->data != searchVal) {
        temp = temp->next;
    }
    if (temp->data != searchVal) {
        cout << "Node with value " << searchVal << " not found" << endl;
        return;
    }
    Node* newNode = new Node(newVal);
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Testing functions
    insertHead(head, 5);
    insertHead(head, 10);
    insertAtEnd(head, 20);
    insertAfterValue(head, 10, 15);

    cout << "Circular Linked List:" << endl;
    display(head);

    return 0;
}