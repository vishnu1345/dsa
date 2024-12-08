#include<iostream>
using namespace std;

void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]>arr[left]){
        largest = left;
    }

    if(right<=n && arr[largest]>arr[right]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
}

void builheap(int arr[] , int n){
    for(int i=n/2;i>0;i--){
        heapify(arr , n , i);
    }
}

void heapsort(int arr[] , int size , int i){
    builheap(arr , size);

    while(size>1){
        swap(arr[1] , arr[size]);
        size--;

        heapify(arr , size , 1);
    }

}

int main() {
    int arr[] = {0, 12, 11, 13, 5, 6, 7}; // 0 is a dummy value to make it 1-indexed
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // Size of the array excluding the dummy value

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n, 1); // Sort the array using heap sort

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
