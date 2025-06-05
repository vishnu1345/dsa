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

class Queue{
    Node* front ;
    Node* rear; 

    Queue(){
        front = NULL;
        rear = NULL;
    }

    public:
    void push(int x){
        Node* newnode = new Node(x);

        if(rear==NULL){
            front = newnode;
            rear=newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }

    void pop(){
        if(front==NULL){
            return ;
        }
        else{
            Node* temp = front;
            front = temp->next;
            delete temp;
        }
    }
};