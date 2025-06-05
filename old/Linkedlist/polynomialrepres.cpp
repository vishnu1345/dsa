#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    int expo;
    Node* next;

    Node(int val , int expo){
        this->data = val;
        this->expo = expo;
        this->next = NULL;
    }
};

void insertTerm(Node*& head, int coeff, int exp) {
    Node* newTerm = new Node(coeff, exp);
    if (head == NULL) {
        head = newTerm;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTerm;
}

void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "x^" << temp->expo;
        if (temp->next != NULL) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}


Node* solve(Node* pol1 , Node* pol2){
    Node* newnode = new Node(-1 , -1);
    Node* temp = newnode;

    while(pol1!=NULL && pol2!=NULL){
        if(pol1->expo>pol2->expo){
            temp->next = new Node(pol1->data , pol1->expo);
            pol1 = pol1->next;
            temp = temp->next;
        }
        else if(pol1->expo<pol2->expo){
            temp->next = new Node(pol2->data , pol2->expo);
            pol2 = pol2->next;
            temp = temp->next;
        }
        else{
            int data = pol1->data + pol2->data;
            int expo = pol1->expo + pol2->expo;
            temp->next = new Node(data , expo);
            pol1 = pol1->next;
            pol2 = pol2->next;
            temp = temp->next;
        }

    }
    while(pol1!=NULL){
    temp->next = pol1;
        pol1 = pol1->next;
    temp =temp->next;
    }
    while(pol2!=NULL){
    temp->next = pol2;
        pol2 = pol2->next;
        temp=temp->next;
    }

    newnode = newnode->next;
    return newnode;
}

int main() {
    Node* pol1 = NULL;
    Node* pol2 = NULL;

    // Polynomial 1: 3x^4 + 2x^3 + 1x^0
    insertTerm(pol1, 3, 4);
    insertTerm(pol1, 2, 3);
    insertTerm(pol1, 1, 0);

    // Polynomial 2: 5x^3 + 6x^2 + 4x^0
    insertTerm(pol2, 5, 3);
    insertTerm(pol2, 6, 2);
    insertTerm(pol2, 4, 0);

    cout << "Polynomial 1: ";
    printPolynomial(pol1);

    cout << "Polynomial 2: ";
    printPolynomial(pol2);

    Node* result = solve(pol1, pol2);

    cout << "Resultant Polynomial: ";
    printPolynomial(result);

    return 0;
}