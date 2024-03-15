#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        char ch[n+1];
        for(int i=0;i<n;i++){
            cin>>ch[i];
        }
        int countQ=0;
        int countA=0;
        for(int i=0;i<n;i++){
            if(ch[i]=='A')  countA++;
            if(ch[i]=='Q')  countQ++;
        }
        if(countA>=countQ){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
