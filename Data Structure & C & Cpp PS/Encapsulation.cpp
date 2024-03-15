#include<bits/stdc++.h>
using namespace std;
class Student{
public:
    int year;
    void sayHi(){
        cout<<"Hi"<<" "<<year<<endl;
    }
};
int main(){
    Student students;
    students.year=2023;
    students.sayHi();
    return 0;
}
