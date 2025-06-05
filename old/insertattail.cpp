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

void insertattail(Node* &head , int data){
    
    Node* newnode = new Node(data);

    Node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newnode;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertattail(head , 11);
    insertattail(head , 12);
    insertattail(head , 13);
    print(head);
    
}