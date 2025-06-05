#include<iostream>
using namespace std;

class priorityqueue{
    vector<int> arr;
    public:
    void insert(int val){
        arr.push_back(val);
        int i = arr.size()-1;
        int parent = (i-1)/2;
        while (i > 0 && arr[parent] < arr[i]) {
            swap(arr[parent], arr[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void heapify(int i){
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
            heapify(largest);
        }
    }
    int pop(){
        int el = arr[0];
        int size = arr.size();
        arr[0] = arr[size-1];
        arr.pop_back();
        heapify(0);

        return el;
    }

    void printQueue() {
        for (int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    priorityqueue pq;

    // Test insertions
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(30);

    cout << "Priority Queue after insertions: ";
    pq.printQueue();

    // Test popping
    cout << "Popped element: " << pq.pop() << endl;

    cout << "Priority Queue after popping: ";
    pq.printQueue();

    return 0;
}