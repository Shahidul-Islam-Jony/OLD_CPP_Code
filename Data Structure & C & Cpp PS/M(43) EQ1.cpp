#include<bits/stdc++.h>
using namespace std;


int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N,C;
        cin>>N>>C;
        int A[N];
        int totalCandyNeed=0;
        for(int k=1;k<=N;k++){
            cin>>A[k];
            int a=A[k]+A[k];
            totalCandyNeed += a;
        }
        if(totalCandyNeed <= C){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }

    return 0;
}
