#include<iostream>
using namespace std;

void heapify(int arr[] , int size , int i){
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;

    if(left<=size && arr[left]>arr[largest]){
        largest = left;
    }

    if(right<=size && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[i] , arr[largest]);

        heapify(arr , size , largest);
    }
}

void heapsort(int arr[] , int n ){
    // build heap 
    for(int i=n/2;i>=1;i--){
        heapify(arr , n , i);
    }

    int size = n;
    while(size>1){
        swap(arr[1] , arr[size]);
        size--;

        heapify(arr , size , 1);
    }
}

void printArray(int arr[], int n) {
    for (int i = 1; i <=n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
     int arr[] = {-1 , 12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n-1);

    heapsort(arr, n-1);

    cout << "Sorted array: ";
    printArray(arr, n-1);


}