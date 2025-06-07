#include<iostream>
using namespace std;

bool dfs(int node , vector<int> adj[] , vector<int> &visited , vector<int> &pathvisited){
    visited[node] = 1;
    pathvisited[node] = 1;

    for(auto it : adj[node]){
        // when the node is not visited
        if(!visited[it]){
            if(dfs(it , adj , visited , pathvisited)){
                return true;
            }
        }
        // if the node has been previously visited
		// but it has to be visited on the same path
        else if (pathvisited[it]) {
            return true;
        }

    }

    pathvisited[node] = 0;

    return false;
}

bool isCyclic(int V, vector<int> adj[]) {

    vector<int> visited(V , 0);
    vector<int> pathvisited(V , 0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i , adj , visited , pathvisited)){
                return true;
            }
        }
    }

    return false;

}