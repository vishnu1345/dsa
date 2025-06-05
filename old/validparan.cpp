#include<iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char> s;

    string str;
    cin>>str;

    for(int i=0;i<str.length();i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }
        else{
            if(!s.empty()){
                char ch = s.top();
                if((str[i]==')'&&ch=='(')|| (str[i]=='}'&&ch=='{') || (str[i]==']'&&ch=='[')){
                    s.pop();
                }
                else{
                    cout<<"invalid paranthesis"<<endl;
                    break;
                }
            }
            else{
                 cout<<"invalid paranthesis"<<endl;
                break;
            }
        }
    }

    if(s.empty()){
        cout<<"valid";
    }
    else{
        cout<<"invalid";
    }
}