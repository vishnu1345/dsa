#include<iostream>
using namespace std;

void dfs(vector<int> adj[] , int node , vector<int> &ans , vector<int> &visited){
    visited[node] = 1;

    ans.push_back(node);

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(adj , it , ans , visited);
        }
    }
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main(){
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans;
    vector<int> visited(5);

    dfs(adj , 0 , ans , visited);

    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}