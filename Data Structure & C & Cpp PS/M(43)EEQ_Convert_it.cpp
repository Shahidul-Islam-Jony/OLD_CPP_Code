#include<bits/stdc++.h>
using namespace std;
vector<int>v;
class heap{
private:
    int leftChild(int i){
        return (i*2)+1;
    }
    int rightChild(int i){
        return (i*2)+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
public:
    void Push(int val){
        //cout<<"Val = "<<val<<endl;
        v.push_back(val);
        int currIndx=v.size()-1;
        //cout<<"parent of this index= "<<v[parent(currIndx)]<<endl;
        while(v[currIndx]<v[parent(currIndx)]){
            if(currIndx==0) break;
            swap(v[currIndx],v[parent(currIndx)]);
            currIndx=parent(currIndx);
        }
    }

    void heapify(int current){
        int sz=v.size()-1;
        if(v[current]<v[sz]){
            int temp=v[sz];
            v[sz]=v[current];
            v[current]=temp;
        }
    }

void pop(){
    int max=v[0];
    int indx;
    for(int i=1;i<v.size();i++){
        if(max<v[i]){
            max=v[i];
            indx=i;
        }
    }
    cout<<max<<endl;
    int size=v.size();
    for(int i=0;i<size;i++){
        if(max==v[i] && i<size){
            while(i<size){
                v[i]=v[i+1];
                i++;
            }
            size--;
        }
    }
}

};

int main()
{
    int val;
    cin>>val;
    queue<int>q;
    heap h;
    q.push(val);
    h.Push(val);
    while(!q.empty())
    {
        int presentVal=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        if(x!=-1)
        {
           q.push(x);
           h.Push(x);
        }
        if(y!=-1)
        {
            q.push(y);
            h.Push(y);
        }
    }

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            h.Push(b);
        }
        if(a==2){
           h.pop();
        }
    }

    return 0;
}


