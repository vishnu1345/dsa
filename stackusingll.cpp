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

class Stack{
    Node* head;

    public:
    Stack(){
        this->head = NULL;
    }

    void push(int x){
        Node* newnode = new Node(x);

        if(newnode==NULL){
            cout<<"stack overflow"<<endl;
        }
        newnode->next=head;
        head = newnode;
    }

    void pop(){
        if(this->head==NULL){
            return ;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int peek(){
        if(this->head==NULL){
            return -1;
        }
        return head->data;

    }
};


int main(){
    Stack st;
st.push(11);
st.push(22);
st.push(33);
st.push(44);

cout << "Top element is " << st.peek() << endl;
cout << "Removing two elements..." << endl;
st.pop();
st.pop();
cout << "Top element is " << st.peek() << endl;
return 0;
}