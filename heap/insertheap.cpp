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
    }

};

int main(){
    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(20);
    h.insert(80);
    h.print();
}