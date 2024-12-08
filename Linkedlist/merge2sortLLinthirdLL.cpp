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

Node* merge(Node* head1 , Node* head2){
    Node* newList = new Node(-1);
    Node* temp = newList;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            temp->next = new Node(head1->data);
            temp = temp->next;
            head1 = head1->next;
        }
        else{
            temp->next = new Node(head2->data);
            temp = temp->next;
            head2 = head2->next;
        }
    }

    while(head1!=NULL){
        temp->next = new Node(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }
    while(head2!=NULL){
        temp->next = new Node(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }

    newList = newList->next;
    return newList;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Create the first sorted linked list
    insertbeg(head1, 10);
    insertbeg(head1, 8);
    insertbeg(head1, 5);
    insertbeg(head1, 3);

    // Create the second sorted linked list
    insertbeg(head2, 15);
    insertbeg(head2, 12);
    insertbeg(head2, 6);
    insertbeg(head2, 4);

    cout << "First Sorted Linked List:" << endl;
    printList(head1);

    cout << "Second Sorted Linked List:" << endl;
    printList(head2);

    // Merge the two sorted linked lists
    Node* mergedHead = merge(head1, head2);

    cout << "Merged Sorted Linked List:" << endl;
    printList(mergedHead);

    return 0;
}