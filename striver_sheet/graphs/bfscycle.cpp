#include<iostream>
using namespace std;;


class Solution {
    public:
    
    bool detect(int src, vector<int> adj[], vector<int> &vis) {
        vis[src] = 1; 
        // store <source node, parent node>
        queue<pair<int,int>> q; 
        q.push({src, -1}); 
        // traverse until queue is not empty
        while(!q.empty()) {
            int node = q.front().first; 
            int parent = q.front().second; 
            q.pop(); 
            
            // go to all adjacent nodes
            for(auto adjacentNode: adj[node]) {
                // if adjacent node is unvisited
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1; 
                    q.push({adjacentNode, node}); 
                }
                // if adjacent node is visited and is not it's own parent node
                else if(parent != adjacentNode) {
                    // yes it is a cycle
                    return true; 
                }
            }
        }
        // there's no cycle
        return false; 
    }
    
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
          vector<int> adj[V];
          
          for(int i=0;i<edges.size();i++){
              int u = edges[i][0];
              int v = edges[i][1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          queue<pair<int , int>> q;
          
          vector<int> visited(V);
          
          for(int i=0;i<V;i++){
              if(!visited[i]){
                  if(detect(i,adj,visited)) return true;
              }
          }
          
          return false;
          
      }
  };