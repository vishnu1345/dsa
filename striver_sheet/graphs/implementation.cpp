#include<iostream>
using namespace std;

int main(){

    int n ; // no. of nodes
    int m ; // no. of edges 
    cin>>n>>m;



    // adjacenecy matrix
    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int u ,  v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1; // only in case of undirected graph
    }
    // space complexity is n^2




    // adjacenecy list 
    vector<int> adj2[n+1];
    for(int i=0;i<m;i++){
        int u ,  v;
        cin>>u>>v;
        adj2[u].push_back(v);
        adj2[v].push_back(u); //  only if undirected graph
    }
    // space complxity - O(2*E) if undirected 
    // and O(E) if directed 



    // weigted graph in adj matrix
    // adj[u][v] = wt;

    
    // weighted graph in adj list 
    // vector<int, pair<int, int>> adj;
    // adj[u].push_back({v  , wt});
}