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


void insertafterval(Node* &head , int num , int val){
    Node* temp = head;
    Node* newnode = new Node(val);
    while(temp!=NULL && temp->data!=num){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<num<<" not found "<<endl;
    }
    else{
        newnode->next = temp->next;
        temp->next = newnode;
        cout<<num<<" inserted"<<endl;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertattail(head , 11);
    insertattail(head , 12);
    insertattail(head , 13);
    insertattail(head , 14);
    insertattail(head , 15);
    print(head);

    insertafterval(head , 13 , 16);
    insertafterval(head , 16 , 17);
    insertafterval(head , 1 , 17);
    
    insertafterval(head , 15 , 18);
    print(head);
}