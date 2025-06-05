#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to create a circular linked list from 1 to n
Node* createCircularLinkedList(int n) {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head; // Make it circular
    return head;
}

// Function to find the survivor position
int findSurvivor(int n, int k) {
    Node* head = createCircularLinkedList(n);
    Node* temp = head;

    // Iterate until only one node is left
    while (temp->next != temp) {
        // Traverse (k-1) nodes to reach the node before the one to be removed
        for (int count = 1; count < k - 1; count++) {
            temp = temp->next;
        }
        // Remove the k-th node
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        // Move to the next node after the deleted one
        temp = temp->next;
    }

    int survivor = temp->data;
    delete temp; // Clean up the last node
    return survivor;
}

// Main function
int main() {
    int n=7;
    int k =3;
    // cout << "Enter the total number of persons (N): ";
    // cin >> n;
    // cout << "Enter the skip count (K): ";
    // cin >> k;

    int survivor = findSurvivor(n, k);
    cout << "The position to survive is: " << survivor << endl;

    return 0;
}
