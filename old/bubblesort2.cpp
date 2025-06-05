// descending bubble sort
#include<iostream>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[5] = {8,1,7,5,2};
    int n = 5;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    display(arr , n);
}