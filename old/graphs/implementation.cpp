#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int , list<int> > adj;

    void addedge(int u , int v , bool direction){
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto it:adj){
            cout<<it.first<<"-> ";
            for(auto j: it.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;

    int n;
    cout<<"enter number of edges ";
    cin>>n;

    for(int i=0;i<n;i++){
        int u , v;
        cout<<"enter adjacent edges ";
        cin>>u>>v;
        g.addedge(u , v , 0);
    }

    g.print();
}