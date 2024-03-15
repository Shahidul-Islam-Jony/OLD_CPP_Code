#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int globalId=100;

class person{
    string name;
    int id;
    float salary;

public:
    //setting null first to avoid garbaje value;
    person(){
        name="";
        id=-1;
        salary=-1.0;
    }
    //Setter function..
    void setName(string name){
        this->name=name;
    }
    void setSalary(float salary){
        this->salary=salary;
    }

    //constructor...
    person(string name,float salary){
        setName(name);    //this->name=name;
        setSalary(salary);        //this->salary=salary;
        id =globalId;
        globalId++;
    }

    //Getter function..
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;
    }
    void print(){
        cout<<name<<" | "<<id<<" | "<<salary<<endl; //cout<<this.getName()<<this.getId()<<....
    }
};

int main()
{
    Stack <person> st;
    person a("Akib zaman",654.6);
    person b("Rohim Box",200.6);
    person c("Farid Ahamed",354.7);
    st.push(a);
    st.push(b);
    st.push(c);

    while(!st.empty()){
        person printObj;
        printObj=st.pop();
        printObj.print();
    }

    //comment out for top and comment while..
//    person printObj;
//    printObj=st.Top();
//    printObj.print();

    return 0;
}
