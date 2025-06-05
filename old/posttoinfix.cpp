#include<iostream>
#include<stack>
using namespace std;

bool isoperator(char ch){
   return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main(){
    string expr="ab*c+";
    stack<string> st;
    for(int i=0;i<expr.length();i++){
        if(isoperator(expr[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string infix = "(" + op2 + " " + expr[i] + " " + op1 + ")";
            st.push(infix);
        }
        else{
            st.push(string(1,expr[i]));
        }
    }

    cout<<st.top();
}