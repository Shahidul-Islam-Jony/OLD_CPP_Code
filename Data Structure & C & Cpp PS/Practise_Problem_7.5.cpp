#include<bits/stdc++.h>
using namespace std;
class Shop{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];

protected:
    int total_income;
public:
    int numOfProduct;
    Shop(string product_name[],int product_price[],int product_quantity[],int n){
        numOfProduct=n;
        for(int i=0;i<n;i++){
            this->product_name[i]=product_name[i];
            this->product_price[i]=product_price[i];
            this->product_quantity[i]=product_quantity[i];
        }
    }

    void setter(int income){
        total_income=income;
    }
};

Shop *Item(){
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
    int n;
    cout<<"Number of products:";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Product "<<i+1<<" Name : ";
        cin>>product_name[i];
        cout<<"Product "<<i+1<<" Price : ";
        cin>>product_price[i];
        cout<<"Product "<<i+1<<" Quantity : ";
        cin>>product_quantity[i];
    }
    Shop *item=new Shop(product_name,product_price,product_quantity,n);
    return item;
}

void show_item(Shop *item){
    cout<<"\t\t\t\t"<<"BUY PRODUCT"<<"\t\t\t"<<endl;
    cout<<"\t\t\t\t"<<"_____________"<<"\t\t\t"<<endl;
    cout<<"Product Index";
    int n=item->numOfProduct;
    for(int i=0;i<n;i++){
        cout<<"\t\t\t"<<i+1;
    }
    cout<<endl;
    cout<<"Product Name";
    for(int i=0;i<n;i++){
        cout<<"\t\t\t"<<item->product_name[i];
    }
    cout<<endl;

    cout<<"Product Price";
    for(int i=0;i<n;i++){
        cout<<"\t\t\t"<<item->product_price[i];
    }
    cout<<endl;

    cout<<"Product Quantity";
    for(int i=0;i<n;i++){
        if(i==0)    cout<<"\t\t"<<item->product_quantity[i];
        else    cout<<"\t\t\t"<<item->product_quantity[i];
    }
    cout<<endl;
}

class User{
public:
    int prouct;
    int quantity;
    User(int product,int quantity){
        this->prouct=product;
        this->quantity=quantity;
    }
};

User *input_user(Shop *item){
    int n=item->numOfProduct;
    int productNo;
    cout<<"which product do you want ? From 1 to "<<n<<":";
    cin>>productNo;
    cout<<"What is the quantity that you want of "<<item->product_name[productNo-1]<<":";
    int quantity;
    cin>>quantity;
    User *a=new User(productNo,quantity);
    return a;
}


void display_user(User* person,Shop* item){
    cout<<"Buy Successful"<<endl;
}

int main(){
    Shop *item=Item();
    show_item(item);
    User *person=input_user(item);
    display_user(person,item);
    return 0;
}
