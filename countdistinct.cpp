#include<bits/stdc++.h>
using namespace std;


void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


int main(){
     int arr[10]={1,2,20,2,5,2,4,2,2,2};
    int n =10;
    sort(arr , arr+10);
    display(arr , n);

    int i = 0;
    int j = i+1; 
    int cnt =1;
    while(j<n){
        if(arr[i]!=arr[j]){
            i=j;
            cnt++;
            j++;
        }
        else{
            j++;
        }
    }
    // display(arr , j);
    cout<<cnt;

}