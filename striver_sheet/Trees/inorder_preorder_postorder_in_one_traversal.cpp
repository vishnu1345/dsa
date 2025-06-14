#include<iostream>
using namespace std;

class Node{
    public:

    int val;
    Node* left;
    Node* right;

    Node(int d){
        val = d;
        left = NULL;
        right = NULL;
    }
};



int main(){
    Node* root = new Node(1);

    stack<pair<Node* , int>> st;

    st.push({root , 1});
    vector<int> preorder , inorder , postorder;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second==1){
            preorder.push_back(it.first->val);

            it.second++;

            st.push(it);

            if(it.first->left){
                st.push({it.first->left , 1});
            }

        }
        else if(it.second==2){
            inorder.push_back(it.first->val);

            it.second++;

            st.push(it);

            if(it.first->right){
                st.push({it.first->right , 1});
            }
        }
        else{
            postorder.push_back(it.first->val);
        }

    }


}