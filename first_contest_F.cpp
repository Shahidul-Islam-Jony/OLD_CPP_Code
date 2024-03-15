#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int big;
    if(a>b&&a>c){
       big=a;
       if(b+c==a){
        cout<<"Yes";
        return 0;
       }
    }
    else if(a>b&&a<c){
        big=c;
        if(a+b==c){
            cout<<"Yes";
            return 0;
        }
    }
    else if(b>a&&b>c){
        big=b;
        if(a+c==b){
            cout<<"Yes";
            return 0;
        }
    }
    else{
        big=c;
        if(a+b==c){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
