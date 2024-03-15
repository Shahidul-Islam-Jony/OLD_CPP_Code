#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visit[100];

void bfs(int source){   //level soho value print korte
    queue<pair<int,int>> q;
    q.push({source,0}); // or, q.push(make_pair(source,0));
    while(!q.empty()){
        pair<int,int> parent=q.front(); // parent er modhee queue er fornt capture hobe
        q.pop();
        if(visit[parent.first]==true)   continue;   //parent ekbar visited hole r niche ashbe na.
        cout<<parent.first<<" "<<parent.second<<endl;
        for(int i=0;i<v[parent.first].size();i++){    //parent er vitorer array te children access korte
            int children= v[parent.first][i]; //parent nijei ekta Array.parent er abar array ace.
                                        //orthat 2D array er moto.
            if(visit[children]==false){ //children already visited ki na ta chek korte.
                q.push({children,parent.second+1});       // karon visited hole push korle duplicate hobe.
            }
            visit[parent.first] = true;
        }
    }
}

void dfs(int source){
    cout<<source<<endl;
    visit[source]=true;
    for(int i=0;i<v[source].size();i++){
        int children=v[source][i];
        if(visit[children]==false){
            dfs(children);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<endl;
    memset(visit,false,sizeof(visit));  //visit er sob ghore prothome false set korte.
    bfs(1);   //when dfs active then bfs deactive because we use same visit array.
    cout<<endl;
//    dfs(1);
//    cout<<endl;
    return 0;
}

/*
input for bfs

6 7
5 3
4 5
1 0
1 2
1 3
3 0
4 3

input for dfs

7 7
1 2
1 6
2 3
2 4
6 4
6 7
4 5

*/
/*
//shudhu value print korte.
void bfs(int source){
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int parent=q.front(); // parent er modhee queue er fornt capture hobe
        q.pop();
        if(visit[parent]==true)   continue;   //parent ekbar visited hole r niche ashbe na.
        cout<<parent<<endl;
        for(int i=0;i<v[parent].size();i++){    //parent er vitorer array te children access korte
            int children= v[parent][i]; //parent nijei ekta Array.parent er abar array ace.
                                        //orthat 2D array er moto.
            if(visit[children]==false){ //children already visited ki na ta chek korte.
                q.push(children);       // karon visited hole push korle duplicate hobe.
            }
            visit[parent] = true;
        }
    }
}
*/

