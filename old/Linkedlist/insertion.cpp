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

void insertbeg(Node* &head , int val){
    if(head==NULL){
        head = new Node(val);
        return ;
    }

    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void inserttail(Node* head , int val){
    if(head==NULL){
        head = new Node(val);
        return ;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void insertafterval(Node* head , int val , int data){
    Node* newNode = new Node(data);

    Node* temp = head;

    while(temp!=NULL && temp->data!=val){
        temp = temp->next;
    }

    try{
    if(temp== NULL){
        throw 0;
    }
    }
    catch(int x){
        cout<<"value not present"<<endl;
        return;
    }
    Node* nextN = temp->next;
    temp->next = newNode;
    newNode->next = nextN;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertbeg(head, 10);
    insertbeg(head, 20);
    inserttail(head, 30);
    inserttail(head, 40);

    cout << "Linked List after insertions:" << endl;
    printList(head);

    cout << "Inserting 25 after 20:" << endl;
    insertafterval(head, 20, 25);
    printList(head);

    cout << "Inserting 35 after 30:" << endl;
    insertafterval(head, 30, 35);
    printList(head);

    cout << "Trying to insert 50 after a non-existent value 100:" << endl;
    insertafterval(head, 100, 50);

    return 0;
}