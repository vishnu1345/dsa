// time complexity = O(n^2)
#include<iostream>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


int main(){
    int arr[10]={1,2,2,2,2,2,4,2,2,2};
    int n = 10;
    int ans[10];
    int k=0;
    for(int i=0;i<n;i++){
       int isdup = 0;
       for(int j=0;j<k;j++){
        if(arr[i]==ans[j]){
            isdup = 1;
            break;
        }
       }

       if(!isdup){
        ans[k]=arr[i];
        k++;
       }
    }

    display(ans , k);
}