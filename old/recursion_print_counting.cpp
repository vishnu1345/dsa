#include <bits/stdc++.h>
using namespace std;

int print(int n){
    if (n==1)
    {
        cout<<n<<" ";
        return 1;
    }
    cout << n<< " ";
    print(n-1);
    
}
int main(){
    int n =10;
    print(n);
}