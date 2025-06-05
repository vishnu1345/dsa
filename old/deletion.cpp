// deletion using index
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
    int arr[5]={1,2,2,3,4};
    int n=5;
    display(arr , n);
    cout<<"after deletion"<<endl;
    n = deletion(arr , 2 , n);
    display(arr , n);
}