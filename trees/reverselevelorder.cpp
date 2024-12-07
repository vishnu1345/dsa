#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to perform reverse level-order traversal
void reverseLevelOrderTraversal(Node* root) {
    if (!root) return;

    // Use a queue for level-order traversal and a stack to reverse the order
    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Push the current node onto the stack
        s.push(temp);

        // Enqueue right child first, then left child (to reverse order in the stack)
        if (temp->right) q.push(temp->right);
        if (temp->left) q.push(temp->left);
    }

    // Pop nodes from the stack to print in reverse level order
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main() {
    // Example binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << "Reverse Level Order Traversal: ";
    reverseLevelOrderTraversal(root);

    return 0;
}
