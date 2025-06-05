#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin , str);
    stack<char> s;
    string ans = "";
    
    for(int i=0;i<str.length();i++){
        if(str[i]!=' '){
            s.push(str[i]);
        }
        else{
            while(!s.empty()){
            ans += s.top();
            s.pop();
            }
            ans+=" ";
        }
    }
    
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }

    cout<<ans<<endl;
}