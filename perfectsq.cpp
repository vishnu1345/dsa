#include<iostream>
using namespace std;

bool isperfect(int n){
    int r = n/2;
    int l = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(mid*mid==n){
            return true;
        }
        else if(mid*mid<n){
            l = mid+1;
        }
        else r = mid-1;
    }
    return false;
}

int main(){
    int n ;
    cin>>n;
    if(isperfect(n)){
        cout<<"it is perfect square"<<endl;
    }
    else cout<<"it is not"<<endl;
}