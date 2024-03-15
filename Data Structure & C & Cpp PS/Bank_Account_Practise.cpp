#include<bits/stdc++.h>
using namespace std;
class BankAccount{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;

public:
    BankAccount(string account_holder,string address,int age,string password){
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->balance=0;
        this->account_number=rand()%10000000;
        cout<<"Your account number is "<<this->account_number<<endl;
    }
    void add_money(string password,int amount){
        if(this->password==password){
            this->balance += amount;
            cout<<"Add money successful"<<endl;
        }
        else{
            cout<<"Password did not match "<<endl;
        }
    }
    int show_balance(string password){
        if(this->password==password){
            return this->balance;
        }
        else{
            return -1;
        }
    }

};
BankAccount* create_account(){
    string account_holder,address,password;
    int age;
    cout<<"CREATE ACCOUNT : "<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *MyAccount=new BankAccount(account_holder,address,age,password);
    return MyAccount;
}
void add_money(BankAccount *MyAccount){
    string password;
    int amount;
    cout<<"Add Money"<<endl;
    cin>>password>>amount;
    MyAccount->add_money(password,amount);
    cout<<"Your Bank balance is "<<MyAccount->show_balance(password)<<endl;
}

int main(){
    BankAccount *MyAccount=create_account();
    add_money(MyAccount);
    return 0;
}
