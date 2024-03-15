#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int count[1001]={0};
        for(int i=0;i<n;i++){
            int val=a[i];
            count[val]++;
        }
        int max=count[0];
        for(int val=1;val<1001;val++){
           if(count[val]>max){
            max=count[val];
           }
        }
        cout<<n-max;
        cout<<endl;
    }
    //counter should 1001..
    return 0;
}
