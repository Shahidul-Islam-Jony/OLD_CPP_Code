#include<bits/stdc++.h>
using namespace std;
class Example{
public:
    int x;
public:
    Example(int a){
        x=a;
    }
    int operator +(Example obj){
       // cout<<x<<" "<<obj.x<<endl;
       //cout<<x+obj.x<<endl;
      // Example ans(0);
       //ans.x=x+obj.x;
       //return ans;
       return x+obj.x;
    }
};
int main(){
    Example a(10),b(20),c(30);
    //Example ans=a+b;
    //cout<<ans.x<<endl;
    //Example ans2=ans+c;
    //cout<<ans2.x<<endl;

    int ans=a+b;
    cout<<ans<<endl;
    Example ansObj(ans);
    cout<<ansObj+c<<endl;
    return 0;
}
