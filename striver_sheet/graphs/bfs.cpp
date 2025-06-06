#include<iostream>
using namespace std;


void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

void bfs(vector<int> adj[] , int n){
    queue<int> q;
    vector<int> visited(n);

    q.push(0);
    visited[0] = 1;

    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
   
         q.pop();
        bfs.push_back(node);

        for(int it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
            
        }
    }

    printAns(bfs);
    
}


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    bfs(adj , 5);


    return 0;
}