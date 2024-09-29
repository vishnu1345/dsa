#include<iostream>
using namespace std;


class Stack{
    int top1;
    int top2;
    int *arr;
    int size;

    public:
    Stack(int n){
        size = n;
        arr = new int[n];
        top1=-1;
        top2=size;
    }

   void push1(int x){
    if(top1<top2-1){
        top1++;
        arr[top1]=x;
    }
    else cout<<"stack overflow";
   }

   void push2(int x){
    if(top1<top2-1){
        top2--;
        arr[top2]=x;
    }
    else cout<<"stack overflow";
   }

   int pop1(){
    if(top1==-1){
        return -1;
    }
    else{
        int el = arr[top1];
        top1--;
        return el;
    }
   }

   int pop2(){
    if(top2==size){
        return -1;
    }
    else{
        int el = arr[top2];
        top2--;
        return el;
    }
   }
};


int main(){
    Stack ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is " << ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2(); 
}