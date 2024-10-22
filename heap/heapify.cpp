#include<iostream>
using namespace std;

void heapify(int arr[] , int n , int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l<=n && arr[l]>arr[largest]){
        largest = l;
    }

    if(r<=n && arr[r]>=arr[largest]){
        largest = r;
    }

    if(l!=i){
        swap(arr[largest] , arr[i]);
        
        heapify(arr , n , largest);
    }
    
}