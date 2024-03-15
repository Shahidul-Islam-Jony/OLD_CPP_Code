#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int count[101]={0};
    for(int i=1;i<=N;i++){
        int j=i;
        while(j%2==0){
            j=j/2;
            count[i]++;
        }
    }
    int cnt=count[1];
    int ans=1;
    for(int i=2;i<=N;i++){
        //cout<<i<<" "<<count[i]<<endl;
        if(count[i]>cnt){
            cnt=count[i];
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
