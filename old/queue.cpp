#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    q.push(10);
    q.push(15);
    q.push(13);

    cout<<"size is"<<q.size()<<endl;
    cout<<"front is"<<q.front()<<endl;
    cout<<"back is"<<q.back()<<endl;

    q.pop();
    cout<<"front is"<<q.front()<<endl;
    cout<<"back is"<<q.back()<<endl;

    q.pop();
     cout<<"size is"<<q.size()<<endl;
    cout<<"front is"<<q.front()<<endl;
    cout<<"back is"<<q.back()<<endl;
     
}