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
        this->account_number=rand()%100000000;
        this->balance=0;
        cout<<"Your account number is "<<this->account_number<<endl;
    }
    int show_balance(string password){
        if(this->password==password){
            return this->balance;
        }
        else{
            return -1;
        }
    }
    void add_money(string password,int amount){//receiving pass and amount from add-money function;
        if(amount<0){
            cout<<"Invalid amount"<<endl;
            return;
        }
        if(this->password==password){
            this->balance+=amount;
            cout<<"Add money successful"<<endl;
        }
        else{
            cout<<"Password didn't match"<<endl;
        }
    }

    void deposit_money(string password,int amount){//receiving pass and amount from deposit-money function;
        if(amount<0){
            cout<<"Invalid amount"<<endl;
            return;
        }
        if(this->balance<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(this->password==password){
            this->balance-=amount;
            cout<<"Deposit money successful"<<endl;
        }
        else{
            cout<<"Password didn't match"<<endl;
        }
    }
    friend class MyCash;
};

class MyCash{
protected:
    int balance;
public:
    MyCash(){
        this->balance=0;
    }
    void add_money_from_bank(BankAccount *myAccount,string password,int amount){
        if(amount<0){
            cout<<"Invalid amount"<<endl;
            return;
        }
        if(myAccount->balance<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(myAccount->password==password){
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"Add money from bank is successful"<<endl;
        }
        else{
            cout<<"Password didn't match"<<endl;
        }
    }
    int show_balance(){
        return balance;
    }
};

BankAccount* create_account(){
    string account_holder,password,address;
    int age;
    cout<<"CREATE ACCOUNT :"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount=new BankAccount(account_holder,address,age,password);
    //int *arr = new int[];
    return myAccount;//returning pointer account..
}

void add_money(BankAccount *myAccount){//receiving pointer object from main class;
    string password;
    int amount;
    cout<<"ADD MONEY"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);//sending pass and amount to Bank class add money;
    cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}

void deposit_money(BankAccount *myAccount){//receiving pointer object from main class;
    string password;
    int amount;
    cout<<"DEPOSIT MONEY"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);//sending pass and amount to Bank class deposit money;
    cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
}

void add_money_from_bank(MyCash *myCash, BankAccount* myAccount){
    string password;
    int amount;
    cout<<"ADD MONEY FROM BANK"<<endl;
    cin>>password>>amount;
    myCash->add_money_from_bank(myAccount,password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
    cout<<"MyCash balance is "<<myCash->show_balance()<<endl;
}

int main(){
    BankAccount *myAccount= create_account();//receiving pointer account..
    //cout<<"Your bank balance is "<<myAccount->show_balance()<<endl;

   /* if(myAccount->show_balance("abc") ==-1){
        cout<<"Password didn't match"<<endl;
    }
    else{
        cout<<"Your bank balance is "<<myAccount->show_balance("abc")<<endl;
    }*/

    /*add_money(myAccount);//sending myAccount parameter to add-money function;
    deposit_money(myAccount);//sending myAccount parameter to deposit-money function;

    MyCash *myCash =new MyCash();
    add_money_from_bank(myCash,myAccount);*/

    MyCash *myCash=new MyCash();

   /*// while(true){
        cout<<"Select option: "<<endl;
        cout<<"1. Add Money to Bank"<<endl;
        cout<<"2. Deposit Money from Bank"<<endl;
        cout<<"3.Add Money to MyCash from Bank"<<endl;
        int option;
        cin>>option;
        if(option==1){
            add_money(myAccount);
        }
        else if(option==2){
            deposit_money(myAccount);
        }
        else if(option==3){
            add_money_from_bank(myCash,myAccount);
        }
        else{
            cout<<"Invalid option"<<endl;
        }
    }//*/

    Flag:
        cout<<"Select option: "<<endl;
        cout<<"1. Add Money to Bank"<<endl;
        cout<<"2. Deposit Money from Bank"<<endl;
        cout<<"3.Add Money to MyCash from Bank"<<endl;
        cout<<"4.Exit"<<endl;
        int option;
        cin>>option;
        if(option==1){
            add_money(myAccount);
        }
        else if(option==2){
            deposit_money(myAccount);
        }
        else if(option==3){
            add_money_from_bank(myCash,myAccount);
        }
        if(option==4){
            return 0;
        }
        else{
            cout<<"Invalid option"<<endl;
        }
        goto Flag;
    return 0;
}
