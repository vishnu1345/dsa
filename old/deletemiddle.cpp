#include<iostream>
#include<stack>
using namespace std;

void deletemiddle(stack<int> &s , int n , int size){
    if(n==size/2){
        s.pop();
        return ;
    }

    int top = s.top();
    s.pop();

    deletemiddle(s , n+1 , size);
    s.push(top);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int size = s.size();

    deletemiddle(s , 0 , size);
    printStack(s);
}