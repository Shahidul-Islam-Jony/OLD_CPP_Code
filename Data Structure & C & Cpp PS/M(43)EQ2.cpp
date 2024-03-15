#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
public:
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }

    void addEdge(int A,int B){
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    void BFS(int L){
        vector<bool>visited(V,false);
        queue<pair<int,int>>q;
        int level=0;
        int source=0;
        q.push({source,level});
        visited[source]=true;

        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            if(temp.second==L){
                cout<<temp.first<<" ";
            }

            for(auto element: adj[temp.first]){
                 int v=element;
                 if(visited[v]!=true){
                    visited[v]=true;
                    q.push({v,temp.second+1});
                 }
            }
        }

    }

};


int main(){
    int N,E;
    cin>>N>>E;
    Graph g(N);

    for(int i=0;i<E;i++){
        int A,B;
        cin>>A>>B;
        g.addEdge(A,B);
    }
    int L;
    cin>>L;
    g.BFS(L);
    return 0;
}

/*
7 6
0 1
0 2
1 3
1 4
2 5
2 6
2

*/

