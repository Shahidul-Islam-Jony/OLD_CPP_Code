#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
         int cnt=0;
         for(int i=1;i<n;i++){
            int x=max(arr[i-1],arr[i]);
            int y=min(arr[i-1],arr[i]);

            while(2*y<x){
                cnt++;
                y=2*y;
            }
         }
         cout<<cnt<<endl;
    }
    return 0;
}
