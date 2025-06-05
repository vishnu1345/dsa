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

void insertathead(Node* &head , int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

bool search(Node* head , int num){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==num){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

int main(){
     Node* node1 = new Node(10);
    Node* head = node1;
    insertathead(head , 11);
    insertathead(head , 12);
    insertathead(head , 13);
    insertathead(head , 14);
    insertathead(head , 15);

    if(search(head , 5)){
        cout<<"element found"<<endl;
    }
    else cout<<"element not found"<<endl;
    if(search(head , 15)){
        cout<<"element found"<<endl;
    }
    else cout<<"element not found"<<endl;
    if(search(head , 12)){
        cout<<"element found"<<endl;
    }
    else cout<<"element not found"<<endl;
}