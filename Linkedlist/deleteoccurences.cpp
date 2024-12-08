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


int deleteocc(Node* &head , int key){
    int cnt = 0;
    if(key==head->data){
        head = head->next;
        cnt++;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==key){
            temp->next = temp->next->next;
            cnt++;
        }
        temp = temp->next;
    }
    return cnt;
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

    // Insert nodes at the beginning
    insertbeg(head, 10);
    insertbeg(head, 20);
    insertbeg(head, 10);
    insertbeg(head, 30);
    insertbeg(head, 10);

    
    // Insert nodes at the tail
    inserttail(head, 40);
    inserttail(head, 50);


    // Insert a node after a specific value
  
    insertafterval(head, 20, 25);
    
    insertafterval(head, 30, 35);
    printList(head);

    // Deleting all occurrences of a value
    int key = 10;
    cout << "Deleting all occurrences of " << key << " from the list:" << endl;
    int count = deleteocc(head, key);
    cout << key << " was deleted " << count << " times." << endl;
    printList(head);

    return 0;
}
