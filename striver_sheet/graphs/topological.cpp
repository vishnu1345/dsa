#include<iostream>
using namespace std;

void topo(vector<int> adj[] , int V){
    unordered_map<int , int> indegree;

    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
    }

    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for(auto it : indegree){
        if(it.second==0){
            q.push(it.first);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;

            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    for(auto i : topo){
        cout<<i<<" ";
    }
}

int main(){
    int V = 6;
    vector<int> adj[V];

    // Example graph (DAG)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topo(adj, V);

    
}