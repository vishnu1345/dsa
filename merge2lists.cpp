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


void insertattail(Node* &head , int data){
    
    Node* newnode = new Node(data);

    Node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newnode;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}

void solve(Node* &first , Node* &second){
    Node* curr = first;
    Node* next = curr->next;

    Node* curr2 = second;
    Node* next2 = NULL;

    while(next!=NULL && curr2!=NULL){
        if(curr2->data>=curr->data && curr2->data<next->data){
            next2 = curr2->next;
            curr->next = curr2;
            curr2->next = next;

            curr = curr2;
            curr2 = next2;
        }
        else{
            curr = next;
            next = next->next;
        }
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertattail(head , 11);
    insertattail(head , 13);
    insertattail(head , 14);
    insertattail(head , 16);
    insertattail(head , 18);

    Node* node2 = new Node(9);
    Node* head2 = node2;
    insertattail(head2 , 12);
    insertattail(head2 , 13);
    insertattail(head2 , 15);
    insertattail(head2 , 17);


    print(head);
    print(head2);
    
}