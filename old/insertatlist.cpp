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

void insertathead(Node* &head , int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
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
    insertathead(head , 11);

    // print(head);
    insertathead(head , 12);
    print(head);
}