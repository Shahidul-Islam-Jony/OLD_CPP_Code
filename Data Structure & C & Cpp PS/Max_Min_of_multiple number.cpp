#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=50,b=150,c=100,d=200;
    int mx=max(a,max(b,max(c,d)));
    int mn=min(a,min(b,min(c,d)));

    cout<<"Max is = "<<mx<<endl;
    cout<<"Min is = "<<mn<<endl;
    return 0;
}
