#include<bits/stdc++.h>
using namespace std;
class Example{
private:
    int x;
    int pass;//recieve by constructor
public:
    Example(int p){//constructor
        pass=p;
    }
    void setter(int a,int p){
        if(p==pass){
            x=a;
        }
        else{
            cout<<"Password did not match"<<endl;
        }
    }
    int getter(int p){
        if(pass==p){
            return x;
        }
        else{
            cout<<"Pass did not match"<<endl;
            return -1;
        }
    }
};

int main(){
    Example a(1234);//constructor initialization->object+function
    a.setter(1500,1235);
    cout<<a.getter(1235)<<endl;
    return 0;
}
