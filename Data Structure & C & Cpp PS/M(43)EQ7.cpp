#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int>* adj;
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }

    void addEdge(int A,int B){
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    void countingNeighbour(int K){
        int count=0;
        for(auto i:adj[K]){
            count++;
        }
        cout<<count;
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
    int K;
    cin>>K;

    g.countingNeighbour(K);

    return 0;
}
