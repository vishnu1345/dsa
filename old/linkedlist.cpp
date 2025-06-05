#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }


    // destructor to delete free node in a memory 
    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void print(Node* &head , Node* &tail){
    cout<<endl;
    Node* temp = head;

    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
}

// void insertAthead(Node* &head , int data){
//     Node* temp = new Node(data);
//     temp->next = head;
//     head = temp;
// }

void insertAthead(Node* &head,int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
   
}

void insertAttail(Node* &tail , int data){
    Node* temp = new Node(data);
    tail->next=temp;
    // temp->next = NULL;
    tail = temp;
}

void inserAtPos(Node* &tail , Node* &head, int pos , int data){
    Node* temp = head;
    int cnt = 1;

    if(pos==1){
        insertAthead(head ,data);
        return ; 
    }

    while (cnt<pos-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAttail(tail , data);
        return;
    }
    Node* NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
    

}


void deleteN(int pos, Node* &head , Node* &tail){
    Node* temp = head;

    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int cnt = 1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }
    
    Node* temp2 = temp->next;
    if (temp->next == NULL) {
        return;
    }
    if(temp2->next == NULL){
        temp->next = NULL;
        tail = temp;
        delete temp2;
        return ;
    }
    temp->next = temp2->next;
    temp2->next = NULL;
    delete temp2;

}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    // print(node1);

    insertAthead(head , 12);
    //  print(head);

    insertAttail(tail , 14);
    // print(head);

    inserAtPos(tail , head , 2 , 2);
    // print(head);

    inserAtPos(tail , head , 1 , 11);
    // print(head);

    
    inserAtPos(tail , head , 6 , 55);
    // print(head);

    inserAtPos(tail , head , 7 , 65);
    // print(head);

    inserAtPos(tail , head , 1 , 5);
    print(head , tail);

    


    deleteN(3 , head , tail);
    print(head , tail);


    deleteN(1 , head , tail);
    print(head , tail);

    deleteN(6 , head , tail);
    print(head , tail);


    deleteN(5 , head , tail);
    print(head , tail);

     deleteN(1 , head , tail);
    print(head , tail);


    return 0;  
}