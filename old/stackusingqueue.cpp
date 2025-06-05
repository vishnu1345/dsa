#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1,q2;

    public:
    void push(int x){
        q1.push(x);
        cout<<"pushed "<<x<<endl;
    }

    int pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int el = q1.front();
        q1.pop();

        queue<int> q = q1;
        q1=q2;
        q2=q;
        // cout<<"popped ";
        return el;
    }
    int top(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
        
        queue<int> q = q1;
        q1=q2;
        q2=q;

        return temp;
    }
    int size() { return q1.size(); }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size() << endl;
    return 0;
}