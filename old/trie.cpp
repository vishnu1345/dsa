#include<iostream>
using namespace std;

class Trienode{
    public:
    bool isTerminal;
    Trienode* children[26];

    Trienode(){
        isTerminal = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    public:
    Trienode* root;

    Trie(){
        root = new Trienode();
    }

    // void removeword(Trienode* root , string word , int depth){
    //     if(depth == word.size()){
    //         if(!root->isTerminal){
    //             return ;
    //         }
    //         root->isTerminal = false;
    //     }
    //     int index = word[depth] - 'a';
    //      Trienode* child = root->children[index];
    // if (child == NULL) {
    //     return;
    // }
    // removeword(child, word, depth + 1);
    // }
    bool removeword(Trienode* root, string word, int depth) {
    // Base case: if the end of the word is reached
    if (depth == word.size()) {
        if (!root->isTerminal) {
            return false; // Word not found
        }
        root->isTerminal = false; // Unmark the terminal node
        // If the node has no children, it can be deleted by the parent
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false; // Node has children, so don't delete it
            }
        }
        return true; // Node is deletable
    }

    // Recursive case: go to the next character in the word
    int index = word[depth] - 'a';
    Trienode* child = root->children[index];
    if (child == NULL) {
        return false; // Word not found
    }

    // Recursively delete the word and check if the child can be deleted
    bool shouldDeleteChild = removeword(child, word, depth + 1);

    if (shouldDeleteChild) {
        delete child;
        root->children[index] = NULL;
        
        // Check if the current node is deletable
        if (!root->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false; // Node has other children, so don't delete it
                }
            }
            return true; // Node is deletable
        }
    }

    return false;
}

    void insert(string word) {
        Trienode* curr = root;
        for(char c: word){
            int index = c - 'a';
            if(curr->children[index]==NULL){
                curr->children[index] = new Trienode();
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    bool search(string word) {
        Trienode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr = curr->children[index];
        }
        if(curr->isTerminal==true){
            return true;
        }
        else return false;
    }

    void remove(string word){

        removeword(root , word , 0);
    }

};

int main(){
    Trie* obj = new Trie();
    obj->insert("hello");
    obj->insert("help");
    obj->insert("vishnu");
    cout<<obj->search("hello")<<endl;
    cout<<obj->search("help")<<endl;
    cout<<obj->search("vishnu")<<endl;

    obj->remove("help");
    cout<<obj->search("hello")<<endl;
    cout<<obj->search("help")<<endl;
}