#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> edgeWeightPair;

class Graph{
    int V;
    list<edgeWeightPair>* adj;
public:
    Graph(int V){
        this->V=V;
        adj=new list<edgeWeightPair>[V];
    }

   void addEdge(int u,int v,int w){
       adj[u].push_back(make_pair(v,w));
       adj[v].push_back(make_pair(u,w));
   }

   void printNeighbour(int chk){
       cout<<chk<<" : ";
        for(auto it=adj[chk].begin();it!=adj[chk].end();it++){
            cout<<"("<<(*it).first<<", "<<(*it).second<<")";
        }
        cout<<endl;
   }

};


int main(){
    int V,E;
    cin>>V>>E;

    Graph g(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    for(int i=0;i<V;i++){
        g.printNeighbour(i);
    }
    cout<<endl<<endl;

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
