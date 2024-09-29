#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1,s2;

    public:
    void push(int x){
        s1.push(x);
        cout<<"pushed "<<x<<endl;
    }
    int pop(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int el = s2.top();
        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return el;
    }
    int front(){
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int el = s2.top();

         while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return el;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.front()<<endl;

    cout<<"popped "<<q.pop()<<endl;
    cout<<q.front()<<endl;

    cout<<"popped "<<q.pop()<<endl;
    cout<<q.front()<<endl;

    cout<<"popped "<<q.pop()<<endl;
    cout<<q.front()<<endl;

    cout<<"popped "<<q.pop()<<endl;

    q.push(6);
    cout<<"front is "<<q.front()<<endl;
    cout<<"popped "<<q.pop()<<endl;
     cout<<"front is "<<q.front();
}