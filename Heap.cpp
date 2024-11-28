#include<iostream>
using namespace std;
class Heap{
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size +1;
        int i = size;
        arr[i] = size;
        while(i>1){
            int parent = i/2;
            if(arr[parent]<arr[i]){
                swap(arr[i] , arr[parent]);
                i = parent;
            }
            else return ;
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }

    void deleteHeap(){
        arr[1] = arr[size];
        size--;

        int i =1;
        while(i<=size){
            int left = 2*i;
            int right = 2*i+1;
            int largest = i;

            if(left<=size && arr[left]>arr[largest]){
                largest = left;
            }

            if(right<=size && arr[right]>arr[largest]){
                largest = right;
            }

            if(largest==i) return;

            swap(arr[i] , arr[largest]);

            i = largest;
        }
    }
};