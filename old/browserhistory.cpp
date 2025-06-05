#include<iostream>
#include<stack>
#include<string>
using namespace std;

class BrowserHistory{
    string current_page;
    stack<string> backs;
    stack<string> forwards;

    public:
    BrowserHistory(string homepage){
        current_page = homepage;
        cout << current_page << endl;
    }

    void visit(string url){
        backs.push(current_page);

        current_page = url;

        while(!forwards.empty()){
            forwards.pop();
        }

        cout<<current_page<<endl;
    }

    void back(int n){
        while(n>0 && !backs.empty()){
            forwards.push(current_page);
            current_page = backs.top();
            backs.pop();
            n--;
        }
        cout<<current_page<<endl;
    }

    void forward(int n){
        while(n>0 && !forwards.empty()){
            backs.push(current_page);
            current_page = forwards.top();
            forwards.pop();
            n--;
        }
        cout<<current_page<<endl;
    }
};

int main(){
    BrowserHistory browser("ds.org");  
    browser.visit("google.com");      
    browser.visit("facebook.com");    
    browser.visit("youtube.com");     
    browser.back(1);                  
    browser.back(1);                  
    browser.forward(1);              
    browser.visit("linkedin.com");    
    browser.forward(2);               
    browser.back(2);                  
    browser.back(7);    
}