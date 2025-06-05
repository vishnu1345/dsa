#include<iostream>
using namespace std;
class Stack{
    
    int top;

    public:
    int arr[100];
    Stack(){
        this->top = -1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else return false;
    }

    bool isFull(){
        if(top==99){
            return true;
        }
        else return false;
    }

    bool push(int x){
        if(isFull()){
            cout<<"stack overflow";
            return false;
        }
        else{
            top++;
            arr[top]=x;
            return true;
        }
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }
        else{
            int el = arr[top];
            top--;
            return el;
        }
    }
    int top(){
        if(isEmpty()){
            return -1;
        }
        else return arr[top];
    }
};

int main(){

}