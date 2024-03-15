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
    }

   int DFS(int source){
        static vector<bool>visited(V,false);
        static int count=0;
        visited[source]=true;
        for(auto i:adj[source]){
            if(visited[i]!=true){
                count++;
                DFS(i);
            }
        }
        return count;
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

    int cnt=g.DFS(K);
    cout<<cnt<<endl;
    return 0;
}
