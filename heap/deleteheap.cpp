#include<iostream>
using namespace std;

class heap{
    int arr[100];
    int size;

    public:
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
  
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent] , arr[index]);
                index =  parent;

            }
            else{
                return ;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteHeap() {
    if (size == 0) {
        cout << "heap is empty" << endl;
        return;
    }
    
    // Replace root with the last element and reduce size
    arr[1] = arr[size];
    size--;
    
    int i = 1;
    while (i <= size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;
        
        // Check if left child exists and is larger than current
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        
        // Check if right child exists and is larger than largest so far
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
        
        // If current node is already the largest, heap property is restored
        if (largest == i) {
            return;
        }
        
        // Otherwise, swap with the larger child and continue
        swap(arr[i], arr[largest]);
        i = largest;
    }
}


};

int main(){
    heap h;
    h.insert(10);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);
    h.print();
    h.deleteHeap();
    h.print();
    h.deleteHeap();
    h.print();
}