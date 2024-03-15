#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int ans=0;
        int question=0;
        for(int i=0;i<n;i++){
            char ch;
            cin>>ch;
            if(ch=='Q') question++;
            if(question !=0 && ch=='A')  question -= 1;
        }
        if(question==0) cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }

    return 0;
}
