#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(20);
    pq.push(16);
    pq.push(12);
    pq.push(15);
    pq.push(14);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    

}