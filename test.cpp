#include <bits/stdc++.h>
using namespace std;
 
bool ispresent(int arr[] , int k , int s,int e){
    int mid = s+(e-s)/2;
    if(s>e){
        return false;
    }
    if(arr[mid]==k){
        return true;
    }
    else if(arr[mid]>k){
        return ispresent(arr,k,s,mid-1);
    }
    else{
        return ispresent(arr,k,mid+1,e);
    }
   
}

int main(){
    int nums[] = {1,5,6,8,11};
    
    if(ispresent(nums , 17, 0 , 4 )){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}