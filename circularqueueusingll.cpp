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

class circularQueue{
    Node* front;
    Node* rear;

    circularQueue(){
        front = NULL;
        rear = NULL;
    }

    void push(int x){
        Node* newnode = new Node(x);
        if(front==NULL && rear==NULL){
            front = rear = newnode;
            rear->next = front;
        }
        else{
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
    }

    void pop(){
        if(front==NULL){
            return;
        }
        else if(front==rear){
            Node* temp = front;
            front = rear = NULL;
            delete temp;
        }
        else{
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

};