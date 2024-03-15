#include<bits/stdc++.h>
using namespace std;
class Parent{
private:
    int taka;
public:
    Parent(int tk){
        taka=tk;
    }
    friend class Bondhu;
};
class Bondhu{
public:
    void tellSecret(Parent *ptr){
        cout<<ptr->taka<<endl;
    }
};

int main(){
    Parent pt(1500);
    Bondhu dost;
    dost.tellSecret(&pt);
    return 0;
}

