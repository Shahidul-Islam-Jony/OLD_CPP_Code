#include<bits/stdc++.h>
using namespace std;
class Parent{
public:
    int x;
private:
    int y;
protected:
    int z;
public:
    Parent(int a,int b,int c){  //constractor...
        x=a;
        y=b;
        z=c;
    }
};
class Child:public Parent{
public:
    int xx;
    Child(int aa,int a,int b,int c):Parent(a,b,c){
        xx=aa;
    }
    void print_protected(){
        cout<<"Protected value : "<<z<<endl;
    }
};

int main(){
    Parent pt(10,20,30);
    Child ch(100,10,20,30);
    cout<<ch.xx<<endl;
    cout<<pt.x<<endl;
    cout<<ch.x<<endl;
    ch.print_protected();
    return 0;
}
