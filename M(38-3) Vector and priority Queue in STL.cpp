//M(38-3) Vector and priority Queue in STL
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PAIR; //only for pair type// jekono duita dataType use kora jai,jekono name dewa jai.

int main(){

    vector<int> V(3,-1); //3 sizer vector and all value set in -1;
    for(int i=0;i<V.size();i++){
        cout<<V[i]<<" ";    //printing vector value.
    }
    cout<<endl<<endl;

    V.push_back(4);

    //Or also printing like this...->
    //print using iterator
    vector<int> :: iterator it; //vector typer pointer
    for(it=V.begin();it!=V.end();it++){ //where it work with address,,like if it=1000; then it++ means 1000+1*(4)=1004 // as int=4;
        cout<<*it<<" ";    //printing vector value which is stored this address.
    }
    cout<<endl;

    //OR
    //print by 'auto' Register in range based traversal // Just using auto
    for(auto element: V){   // auto dile iterator dewa lage na ba kon dhoroner value ta bola lage na.Auto nijei ta capture kore nei.
        cout<<element<<" "; //Also print by auto register
    }
    cout<<endl;

    //OR, printing by auto register in place of iterator // without iterator,,,Just using auto and vector
    for(auto it=V.begin();it!=V.end();it++){
        cout<<*it<<" "; //eivabeo print kora jai.
    }
    cout<<endl;

// Vector End.



    //PRIORITY QUEUE

    //maximum priority queue
    priority_queue<int,vector<int>> PQ;
    PQ.push(1);
    PQ.push(6);
    PQ.push(2);

    cout<<"Maximum priority queue "<<endl;
    while(!PQ.empty()){
        cout<<PQ.top()<<endl;
        PQ.pop();
    }
    cout<<endl;

    //minimum priority queue
    priority_queue<int,vector<int>,greater<int>> PQ2;
    PQ2.push(1);
    PQ2.push(6);
    PQ2.push(2);

    cout<<"Minimum priority queue "<<endl;
    while(!PQ2.empty()){
        cout<<PQ2.top()<<endl;
        PQ2.pop();
    }
    cout<<endl;


    //For pair Type...
    priority_queue<PAIR,vector<PAIR>,greater<PAIR>> PQ3; //typedef pair declare na korle priority_queue<pair<int,int>,vector<int,int>,greater<int,int>>
    PQ3.push(make_pair(1,9));        //greater<PAIR> na dile Max heap hobe.                                                                   //hobe
    PQ3.push(make_pair(6,2));
    PQ3.push(make_pair(4,1));

    cout<<"Pair type minimum priority queue "<<endl;    //Maximum priority er khetre greater<PAIR> bad dite hobe.
    while(!PQ3.empty()){
        cout<<PQ3.top().first<<" | "<<PQ3.top().second<<endl;
        PQ3.pop();
    }
    cout<<endl;


    return 0;
}
