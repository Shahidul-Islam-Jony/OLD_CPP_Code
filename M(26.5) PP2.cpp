#include<bits/stdc++.h>
#include"MYQUEUE.h"
#include"MYSTACK.h"
using namespace std;

void frequencyCount(Queue<int> q,int array[],int n,int m)
{
    int max=INT_MIN;
    for(int i=0; i<m; i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }
    int count[max+1]= {0};
    while(!q.empty())
    {
        count[q.pop()]++;
    }

    for(int i=0; i<m; i++)
    {
        if(count[array[i]]!=0){
            cout<<count[array[i]]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    Queue<int> q;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        q.push(val);
    }
    int m;
    cin>>m;
    int array[m];
    for(int i=0; i<m; i++)
    {
        cin>>array[i];
    }

    frequencyCount(q,array,n,m);

    return 0;
}
