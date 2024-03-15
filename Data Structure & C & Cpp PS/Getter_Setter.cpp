#include<bits/stdc++.h>
using namespace std;
class Example{
private:
    int x;
public:
   void setter(int a){
        x=a;
    }
    int getter(){
        return x;
    }
};

int main(){
    Example a;
    a.setter(1000);
    cout<<a.getter()<<endl;
    return 0;
}

