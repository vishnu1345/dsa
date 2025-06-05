// time complexity = O(n^3)
#include<iostream>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int deletion(int arr[] , int index , int n){
    for(int i=index;i<=n-2;i++){
        arr[i]=arr[i+1];

    }
    n--;
    return n;
}

int main(){
    int arr[10]={1,2,2,2,2,2,4,2,2,2};
    int n = 10;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                n = deletion(arr , j , n);
                j--;
            }
        }
    }

    display(arr , n);
}