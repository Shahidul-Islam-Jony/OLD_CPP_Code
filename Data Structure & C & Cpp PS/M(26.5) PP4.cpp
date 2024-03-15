#include<bits/stdc++.h>
#include"MYQUEUE.h"
using namespace std;

void reverseQueue(Queue<int> &q){

    if(q.empty()){
        return;
    }
    int frontElement=q.Front();
   // cout<<"Front Element before reverse = "<<frontElement<<endl;
    q.pop();
    reverseQueue(q);
    //cout<<"Front Element after reverse = "<<frontElement<<endl;
    q.push(frontElement);
//    while(!q.empty()){
//        cout<<q.pop()<<" ";
//    }
}

int main(){
    Queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        q.push(val);
    }

    reverseQueue(q);

    cout<<"Queue after reverse : ";
    while(!q.empty()){
        cout<<q.pop()<<" ";
    }
    cout<<endl;

    return 0;
}
