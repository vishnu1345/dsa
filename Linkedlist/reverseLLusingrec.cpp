#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Recursive function to reverse the linked list
Node* reverseRecursive(Node* head) {
    // Base case: If the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the rest of the list
    Node* restReversed = reverseRecursive(head->next);

    // Adjust the pointers
    head->next->next = head;
    head->next = NULL;

    return restReversed; // Return the new head
}

// Utility function to insert a new node at the end
void insertTail(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the recursive reverse
int main() {
    Node* head = NULL;

    // Insert nodes into the linked list
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list using recursion
    head = reverseRecursive(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
