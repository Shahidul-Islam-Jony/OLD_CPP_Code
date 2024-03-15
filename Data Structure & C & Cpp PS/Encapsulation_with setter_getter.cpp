#include<bits/stdc++.h>
using namespace std;

class Student{
private:
    string name;
    int roll;
public:
    void setter(string x,int y){
        name=x;
        roll=y;
    }
    void getter(){
       cout<<name<<" "<<roll<<endl;
    }
};

int main(){
    Student a;
    a.setter("Rodix",5819);
    a.getter();
    return 0;
}
