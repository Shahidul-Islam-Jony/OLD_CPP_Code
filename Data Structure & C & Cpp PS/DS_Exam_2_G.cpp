#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int temp=n;
    int m=0;
    while(temp!=0){
        int div=temp/10;
        int rem=temp%10;
        temp=div;
        m=m*10+rem;
    }
   // cout<<m<<endl;
    //cout<<n<<endl;

    if(n==m){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
