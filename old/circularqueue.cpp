#include<iostream>
using namespace std;

class Cqueue{
    int front;
    int rear;
    int size;
    int *arr;

    public:
    Cqueue(int n){
        size = n;
        arr = new int[size];
        front =-1;
        rear = -1;
    }

    bool isFull(){
        if((front==0 && rear == size-1)||(rear==front-1)){
            return true;
        }
        else return false;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        else return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"queue is full";
        }
        else{
            if(front==-1 && rear==-1){
                front = rear =0;
                
            }
            else if(front!=0 && rear==size-1){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear]=x;
        }
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        else{
            int el = arr[front];
            if(front==rear){
                
                front=rear=-1;
               
            }
            else if(front==size-1){
                front = 0;
            }
            else{
                front++;
            }
            return el;
        }
    }
     void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    Cqueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}