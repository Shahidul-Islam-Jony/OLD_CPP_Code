//M(41-3) Breadth first search
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> edgeWeightPair;
class Graph{
    int V;
    list<edgeWeightPair> *adj;  //pair typer adjacency list.
public:
    Graph(int V){
        this->V=V;
        adj=new list<edgeWeightPair> [V]; //adj list er modhee V size er array list.
    }

    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));   //w means edge value
        adj[v].push_back(make_pair(u,w));   // u and v are array index value.
    }

    void printNeighbour(int chk){
        cout<<chk<<" : ";
        for(auto i=adj[chk].begin();i!=adj[chk].end();i++){ //as i is pair<int,int> type data it increase by 8 bit.
            cout<<"("<<(*i).first<<", "<<(*i).second<<")"<<" ";
        }
    }

    void BFS(int source){
        vector<bool> visited(V,false); // creating boolean type visited array with false
        queue<int> Q;   // int type er queue because Node is int type
        visited[source]=true;
        Q.push(source);

        while(!Q.empty()){
            int u=Q.front();
            cout<<u<<" ";
            Q.pop();

            for(auto element:adj[u]){
                int v=element.first;
                if(visited[v]!=true){
                    visited[v]=true;
                    Q.push(v);
                }
            }
        }
    }

};


int main(){
    int V,E,source; //V=number of nodes, E=Number of edges, source= BFS starting point
    cin>>V>>E>>source;
    Graph g(V); //Graph typer object passing value V.
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }

    for(int i=0;i<V;i++){
        g.printNeighbour(i);
        cout<<endl;
    }
    cout<<endl;

    g.BFS(source);
    cout<<endl;

    return 0;
}

/*

7 10 0
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 6
2 5 8


11 13 0
0 4 1
0 2 2
2 1 3
2 9 4
2 5 5
2 3 6
9 8 7
9 7 8
1 3 9
3 6 10
3 10 11
3 5 12
5 10 13

*/

