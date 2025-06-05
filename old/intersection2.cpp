#include<bits/stdc++.h>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int A[7] = {1,4,3,2,5, 8,9};
    int B[5] = {6,3,2,7,5};

    int n = 7;
    int m = 5;
    int ans[100];
    int i = 0 , j = 0;
    int k = 0;

    sort(A , A+n);
    sort(B , B+m);
    display(A , n);
    display(B , m);

    while(i<n && j<m){
        if(A[i]==B[j]){
            ans[k++]=A[i];
            i++;
            j++;
        }
        else if(A[i]<B[j]){
            i++;
        }
        else j++;
    }

    display(ans , k);
}