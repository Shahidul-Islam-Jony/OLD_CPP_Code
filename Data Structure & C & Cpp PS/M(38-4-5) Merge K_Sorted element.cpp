//M(38-5)Merge K-Sorted Element
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PAIR;

int main(){
    int k;
    cin>>k;

    vector<vector<int>> allValues(k);   //(k) 3 ti array rakhar jonno Dynamic Array.

    //Getting Input
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        allValues[i]=vector<int>(size); // Dynamic array er modhee protita Array er size set korte.
        for(int j=0;j<size;j++){
            cin>>allValues[i][j];
        }
    }

    vector<int>indexTracker(k,0);   //k size er index Tracker jar sob value 0 set kora.
    priority_queue<PAIR,vector<PAIR>, greater<PAIR>> PQ; //creating min heap;

    //Initialization of PQ
    for(int i=0;i<k;i++){
        PQ.push(make_pair(allValues[i][0],i)); //orthet (allValues [0][0],0) means |(1,0)| (allValues[1][0],1) means |(3,1)|
                                    //eivabe push hobe.
    }

    //Main logic of heap
    vector<int>ans;
    while(!PQ.empty()){
        PAIR x=PQ.top();
        PQ.pop();

        ans.push_back(x.first);

       if(indexTracker[x.second]+1 < allValues[x.second].size()){   //increment position validity check
            PQ.push(make_pair(allValues[x.second][indexTracker[x.second]+1], x.second));
            //creating a pair : (Increment position value, increment position array identity)
       }
       indexTracker[x.second]+=1;

    }

    //Printing Answer
    for(auto element:ans){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}

/*

3
3
1 4 7
2
3 5
3
2 6 7

*/
