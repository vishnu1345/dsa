#include<bits/stdc++.h>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[10]={1,2,20,2,2,2,4,2,2,2};
    int n =10;
    sort(arr , arr+10);
    display(arr , n);

    int i=0;
    int ans[10];
    int k = 0;
    ans[k]=arr[i];
            k++;
    for(int i=0;i<n-1;i++){
        
        if(arr[i]!=arr[i+1]){
            ans[k]=arr[i+1];
            k++;
        }
    }
    display(ans , k);
}