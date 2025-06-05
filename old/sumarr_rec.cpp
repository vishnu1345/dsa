#include <bits/stdc++.h>
using namespace std;

int sum(int arr[] , int n){
    if (n==1)
    {
        return arr[n-1];
    }
    // if(n==0){
    //     return 0;
    // }
    // int ans =0;
    int ans = arr[0] + sum(arr+1 , n-1);
    return ans;
}

int main(){
    int arr[5] = {4,2,3,4,6};
    int ans = sum(arr,5);
    cout<<endl<<endl;
    cout<<ans<<endl;
}