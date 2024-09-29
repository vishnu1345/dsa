#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with value : "<<this->data<<endl;
    }
};

void insert(Node* &head , int element , int d){
    if (head==NULL)
    {
        Node* newNode = new Node(d);
        head = newNode;
        newNode->next = newNode;

    }
    else{
        Node* temp = new Node(d);
        Node* curr = head;

        while (curr->data!=element)
        {
            curr=curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    
}
void print(Node* &head){

    Node* temp = head;

    do
    {
        cout<<head->data<<" ";
        head = head->next;
    } while (head!=temp);

    cout<<endl;
    
}
int main(){
    Node* head = NULL;
    insert(head , 0 , 1);
    print(head);

    insert(head , 1 , 3);
    print(head);

    insert(head , 3 , 5);
    print(head);

    insert(head , 1 , 18);
    print(head);

    insert(head , 18 , 6);
    print(head);

    insert(head , 3 , 7);
    print(head);


}