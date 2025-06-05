#include <bits/stdc++.h>
using namespace std;

int main(){
    int max = 0;
    int index;
    int arr[3][3] = {{1,2,9} ,{1,2,8} ,{1,9,4}};
    int sum =0;
    for (int i = 0; i < 3; i++)
    {
        int sum=0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        if(sum>max){
            max = sum;
            index = i;
        }
    }
    cout<<max<<endl;
    cout<<index<<endl;
}