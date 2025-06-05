#include<iostream>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
int findind(int arr[], int val , int n){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int deletion(int arr[] , int index , int n){
    for(int i=index;i<=n-2;i++){
        arr[i]=arr[i+1];

    }
    n--;
    return n;
}

int main(){
    cout<<"enter element you want to delete";
    int val;
    cin>>val;
    int arr[5]={1,2,2,3,4};
    int n = 5;
    int ind = findind(arr , val , n);
    if(ind!=-1){
    n = deletion(arr , ind , n);
    display(arr , n);
    }
    else cout<<"element not found";
}