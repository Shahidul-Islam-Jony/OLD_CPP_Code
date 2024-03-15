/*Function overloading...*/
#include<bits/stdc++.h>
using namespace std;
class Example{
public:
    int add(int x,int y){
        return x+y;
    }
    double add(double x,double y){
        return x+y;
    }
};

int main(){
    Example ex;
    cout<<ex.add(7.5,3.7)<<endl;//double
    cout<<ex.add(1,2)<<endl;//int

    return 0;
}
