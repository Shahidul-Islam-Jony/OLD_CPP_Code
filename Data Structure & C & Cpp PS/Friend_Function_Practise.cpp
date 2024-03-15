#include<bits/stdc++.h>
using namespace std;
class Parent{
private:
    int taka;
protected:
    int pass;
public:
    Parent(int tk,int p){
        taka=tk;
        pass=p;
    }
    friend void tellSecret(Parent *ptr);
};

void tellSecret(Parent *ptr){
    cout<<ptr->taka<<" "<<ptr->pass<<endl;
}
int main(){
    Parent pt(1500,1234);
    tellSecret(&pt);
    return 0;
}
