#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    string exp="231*+9-";

    for(int i=0;i<exp.length();i++){
        if(isdigit(exp[i])){
            s.push(exp[i]-'0');
        }
        else{
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();

            switch (exp[i])
            {
            case '+':
                s.push(val2 + val1);
                break;

            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            
            default:
                break;
            }
        }

    }

    cout<<s.top();
}