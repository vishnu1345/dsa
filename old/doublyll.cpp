#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;

    
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head , Node* &tail , int pos , int d){
    Node* insert = new Node(d);
    Node* temp = head;

    if(pos==1){
        insertAtHead(head , d);
        return;
    }
    int cnt = 1;
    while (cnt<pos-1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail , d);
        return;
    }
    Node* temp2 = temp->next;
    temp->next = insert;
    insert->prev = temp;

    insert->next = temp2;
    temp2->prev = insert; // can be written as temp->next->prev = insert
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* &tail = node1;

    insertAtHead(head , 11);
    // print(head);
    // cout<<"head is "<<head->data<<endl;

    insertAtHead(head , 12);
    // print(head);
    // cout<<"head is "<<head->data<<endl;

    insertAtHead(head , 13);
    // print(head);
    // cout<<"head is "<<head->data<<endl;

    insertAtTail(tail , 9);
    // print(head);
    // cout<<"tail is "<<tail->data<<endl;

    insertAtTail(tail , 8);
    // print(head);
    // cout<<"tail is "<<tail->data<<endl;

    insertAtTail(tail , 7);
    print(head);
    // cout<<"tail is "<<tail->data<<endl;

    insertAtPosition(head , tail , 3 , 52);
    print(head);
        cout<<"head is "<<head->data<<endl;

    insertAtPosition(head , tail , 1 , 40);
    print(head);
        cout<<"head is "<<head->data<<endl;

    insertAtPosition(head , tail , 1 , 58);
    print(head);
        cout<<"head is "<<head->data<<endl;

    insertAtPosition(head , tail , 11 , 22);
    print(head);
    cout<<"tail is "<<tail->data<<endl;

    insertAtPosition(head , tail , 12 , 42);
    print(head);
    cout<<"tail is "<<tail->data<<endl;

 

}