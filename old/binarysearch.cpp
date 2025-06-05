#include<iostream>
using namespace std;
int main(){
    int arr[6]={2,6,8,18,36,86};
    int n;
    cout<<"enter a number to find ";
    cin>>n;
    int low = 0;
    int high = 5;
    int mid;

    while (low<=high)
    {
        
        if (arr[mid]==n)
        {
            cout<<mid<<endl; // return mid 
            break;
        }
        else if (n>arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
        mid=(low+high)/2;
    }
    // return -1; // element not present
}