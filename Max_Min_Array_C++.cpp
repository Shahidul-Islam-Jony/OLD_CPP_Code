#include<bits/stdc++.h>
using namespace std;
int main(){
    int ar[5]={40,50,30,60,80};
    int mx,mn;
    for(int i=0;i<5;i++){
        mx=max(mx,ar[i]);
        mn=min(mn,ar[i]);
    }
    cout<<mx<<endl;
    cout<<mn<<endl;
    return 0;
}
