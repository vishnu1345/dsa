#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> arr;

    public:
    void heapifyup(int i){
        int parent = (i-1)/2;
        if(parent>=0 && arr[parent]<arr[i]){
            swap(arr[parent] , arr[i]);
            heapifyup(parent);
        }
    }

    void heapifydown(int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left<arr.size() && arr[left]>arr[largest]){
            largest = left;
        }   

        if(right<arr.size() && arr[right]>arr[largest]){
            largest = right;
        }

        if(largest!=i){
            swap(arr[largest] , arr[i]);
            heapifydown(largest);
        }
    }

    void push(int val){
        arr.push_back(val);
        heapifyup(arr.size()-1);
    }

    int pop(){
        if (arr.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }

        int maxel = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        heapifydown(0);
        return maxel;
    }

    int top() {
        if (arr.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

     bool empty() {
        return arr.empty();
    }

    int size() {
        return arr.size();
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(40);

    cout << "Priority Queue Size: " << pq.size() << endl;

    // Access the top element
    cout << "Top Element: " << pq.top() << endl;

    // Remove elements based on priority
    cout << "Popped Element: " << pq.pop() << endl;
    cout << "Popped Element: " << pq.pop() << endl;

    cout << "Priority Queue Size after popping: " << pq.size() << endl;

    // Display the top element again
    cout << "Top Element: " << pq.top() << endl;

    return 0;
}