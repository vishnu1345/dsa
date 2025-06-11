#include<iostream>
using namespace std;

class Disjointset{
    vector<int> parent , size;

    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1 , 1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);

        if(ultp_u==ultp_v) return ;
        else if(size[ultp_u] < size[ultp_v]){
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else{
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
        
    }
};

int main(){


}