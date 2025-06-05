#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    string s = "aabbachyerffcha";
    unordered_set<char> letters;
    
    for(char ch : s){
        letters.insert(ch);
    }

    for(char c : letters){
        cout<<c;
    }
    }