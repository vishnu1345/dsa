#include<iostream>
#include<stack>
using namespace std;

int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string s)
{

	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop(); 
		}

		else {
			while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	for(int i=0;i<result.length();i++){
        st.push(result[i]);
    }

    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    cout<<ans;
}

void infixtoprefix(string s){
    stack<char> st;
    

    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    string news="";
    while(!st.empty()){
        news+=st.top();
        st.pop();
    }

    for(int i=0;i<news.length();i++){
        if(news[i]=='('){
            news[i]=')';
        }
        else if(news[i]==')'){
            news[i]='(';
        }
    }

    infixToPostfix(news);
}
int main(){
    string expr = "(A+B^C)*D+E^5";
    infixtoprefix(expr);
}