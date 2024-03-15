#include<bits/stdc++.h>
using namespace std;
class Parent{
private:
    int taka;
protected:
    int password;
public:
    Parent(int tk,int p){
        taka=tk;
        password=p;
    }
    friend class Bondhu;
};
class Bondhu{
public:
    void tellSecret(Parent *ptr){
        cout<<ptr->taka<<endl;
        cout<<ptr->password<<endl;
    }
};

int main(){
    Parent pt(1500,1234);
    Bondhu bondhu;
    bondhu.tellSecret(&pt);

    return 0;
}
