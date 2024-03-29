//M(40-3-4) Implementation of Graph
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

};


int main(){
    int V,E;
    cin>>V>>E;
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

    return 0;
}

/*

7 10
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

*/



