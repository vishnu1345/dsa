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
    cout<<endl;
}

void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    while(next!=NULL){
        curr->next=prev;
        prev=curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    head = curr;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertattail(head , 11);
    insertattail(head , 12);
    insertattail(head , 13);
    insertattail(head , 14);
    insertattail(head , 15);
    cout<<"initailly"<<endl;
    print(head);
    
    reverse(head);
    print(head);
}