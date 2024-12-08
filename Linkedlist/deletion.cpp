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

void deletebeg(Node* &head){

    if(head->next==NULL){
        head = NULL;
        return ;
    }

    Node* temp = head->next;
    delete head;
    head = temp;
}

void deleteend(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void deleteval(Node* head , int val){
    Node* temp = head;
    Node* prev = NULL;

    while(temp && temp->data!=val){
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main() {
    Node* head = NULL;

    // Insert operations
    insertbeg(head, 10);
    insertbeg(head, 20);
    inserttail(head, 30);
    inserttail(head, 40);

    cout << "Linked List after insertions:" << endl;
    printList(head);

    // Insert after a value
    cout << "Inserting 25 after 20:" << endl;
    insertafterval(head, 20, 25);
    printList(head);

    cout << "Inserting 35 after 30:" << endl;
    insertafterval(head, 30, 35);
    printList(head);

    // Insert after a non-existent value
    cout << "Trying to insert 50 after a non-existent value 100:" << endl;
    insertafterval(head, 100, 50);
    printList(head);

    // Delete operations
    cout << "Deleting from beginning:" << endl;
    deletebeg(head);
    printList(head);

    cout << "Deleting from end:" << endl;
    deleteend(head);
    printList(head);

    cout << "Deleting value 25:" << endl;
    deleteval(head, 25);
    printList(head);

    cout << "Trying to delete a non-existent value 100:" << endl;
    deleteval(head, 100);
    printList(head);

    return 0;
}