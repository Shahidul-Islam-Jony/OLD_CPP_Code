#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=0;
    if(n==1 && m==1){
        cout<<"2"<<endl;
    }
    else{
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x=i*i+j;
            int y=i+j*j;

            if(x==n && y==m){
                cnt++;
            }
        }
    }
    cout<<cnt;
    }
    return 0;
}
