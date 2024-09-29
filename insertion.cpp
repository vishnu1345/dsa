#include<iostream>
using namespace std;
void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}

int insert(int arr[] , int num , int pos , int n){
    for(int i=n-1;i>=pos-2;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    n++;
    return n;
}
int main(){
    int arr[10]={1,3,4,5,6};
    int n =5;
    cout<<"array before inserion"<<endl;
   display(arr , n);
   cout<<endl;
    n = insert(arr , 2 , 2 , 5);
    cout<<"array after insertion"<<endl;
    display(arr , n);
}