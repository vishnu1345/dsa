#include<bits/stdc++.h>
using namespace std;

void display(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


int main(){
    int arr1[7]={3,4,6,7,10, 12, 7};
    int arr2[5]={7,11,15, 7};
    int n = 7;
    int m = 4;
    int ans[100];
    int k = 0;
    for(int i=0;i<n;i++){
        int ispresent = 0;
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j]){
                for(int l=0;l<k;l++){
                    if(arr2[j]==ans[l]){
                       ispresent = 1;
                    }
                }
                if(!ispresent){
                    ans[k++]=arr2[j];
                }
                // break;
            }
        }
    }
    display(ans , k);
}