#include <bits/stdc++.h>
using namespace std;

class Stack{

    public:
    int size;
    int top;
    int *arr;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top =-1;
    }

    void push(int d){
        if(size-top>1){
            top++;
            arr[top]=d;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }
     bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.push(6);
    cout<<st.peek()<<endl;
}