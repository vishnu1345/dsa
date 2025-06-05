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

Node* merge(Node* &head1 , Node* &head2){
    Node* temp = head1;
    Node* nextN = temp->next;

    while(nextN!=NULL && head2!=NULL){
        if(head2->data>temp->data && head2->data<=nextN->data){
            
            temp->next = head2;
            head2 = head2->next;
            temp->next->next = nextN;
            temp = temp->next;
            
        }
        else{
            temp = nextN;
            nextN = nextN->next;
        }
    }

    if(head2!=NULL){
        temp->next = head2;
    }

    return head1;
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
    insertbeg(head1, 20);
    insertbeg(head1, 15);
    insertbeg(head1, 10);
    insertbeg(head1, 5);

    // Create the second sorted linked list
    insertbeg(head2, 18);
    insertbeg(head2, 14);
    insertbeg(head2, 9);
    insertbeg(head2, 2);

    cout << "First Sorted Linked List:" << endl;
    printList(head1);

    cout << "Second Sorted Linked List:" << endl;
    printList(head2);

    // Merge the two sorted linked lists
    Node* mergedHead = NULL;
    if(head1->data<head2->data){
    mergedHead = merge(head1, head2);
    }
    else{
        mergedHead = merge(head2, head1);
    }

    cout << "Merged Sorted Linked List:" << endl;
    printList(mergedHead);

    return 0;
}