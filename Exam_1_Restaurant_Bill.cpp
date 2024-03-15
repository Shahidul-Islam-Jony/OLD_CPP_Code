#include<bits/stdc++.h>
using namespace std;

class Restaurant{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    int total_tax;
public:
    int item_num;
    Restaurant(int food_item_codes[],string food_item_names[],int food_item_prices[],int n){
        this->item_num=n;
        for(int i=0;i<item_num;i++){
            this->food_item_codes[i]=food_item_codes[i];
            this->food_item_names[i]=food_item_names[i];
            this->food_item_prices[i]=food_item_prices[i];
        }
    }
    void add_tax(double net_total){
        this->total_tax=net_total;
        cout<<"Net total = "<<total_tax<<endl;
    }
};

class User{
public:
    int table_number;
    int num_of_items;
    int item_code[100];
    int quantity[100];
    User(int table_number,int num_of_items,int item_code[],int quantity[]){
        this->table_number=table_number;
        this->num_of_items=num_of_items;
        for(int i=0;i<num_of_items;i++){
            this->item_code[i]=item_code[i];
            this->quantity[i]=quantity[i];
        }
    }
};

Restaurant* Food_Item(){
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>food_item_codes[i];
        cin.ignore();
        getline(cin,food_item_names[i]);
        cin>>food_item_prices[i];
    }
    Restaurant *food_item=new Restaurant(food_item_codes,food_item_names,food_item_prices,n);
    return food_item;
}
void show_food_item(Restaurant *food_item){
     cout<<"\t\t\t\t\t"<<"MAKE BILL"<<"\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t"<<"_________________________"<<"\t\t\t\t"<<endl;
    cout<<"Item Code"<<"\t\t\t"<<"Item Name"<<"\t\t\t\t"<<"Item Price"<<endl;
    for(int i=0;i<food_item->item_num;i++){
        cout<<food_item->food_item_codes[i]<<"\t\t\t\t"<<food_item->food_item_names[i]<<"\t\t\t"<<food_item->food_item_prices[i]<<endl;
    }
    cout<<endl;
}
User* input_user(){
    int table_number;
    int num_of_items;
    int item_code[100];
    int quantity[100];
    cout<<"Enter Table No :";
    cin>>table_number;
    cout<<"Enter Number of Items : ";
    cin>>num_of_items;
    for(int i=0;i<num_of_items;i++){
        cout<<"Enter Item "<<i+1<<" Code : ";
        cin>>item_code[i];
        cout<<"Enter Item "<<i+1<<" Quantity : ";
        cin>>quantity[i];
    }
    User *input=new User(table_number,num_of_items,item_code,quantity);
    return input;
}
void bill_summary(Restaurant* food_item, User * input){
    double sum=0;
    cout<<"\t\t\t\t\t"<<"BILL SUMMARY"<<"\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t"<<"__________________"<<"\t\t\t"<<endl;
    cout<<"Table No. : "<<input->table_number<<endl;
    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t\t"<<"Item Price"<<"\t\t"<<"Item Quantity"<<"\t\t"<<"Total Price"<<endl;
    for(int i=0;i<input->num_of_items;i++){
        bool found=false;
        for(int j=0;j<food_item->item_num;j++){
            if(input->item_code[i]==food_item->food_item_codes[j]){
                cout<<food_item->food_item_codes[j]<<"\t\t\t"<<food_item->food_item_names[j]<<"\t\t"<<food_item->food_item_prices[j]<<"\t\t\t"<<input->quantity[i]<<"\t\t\t"<<food_item->food_item_prices[j]*input->quantity[i]<<endl;
                sum+=food_item->food_item_prices[j]*input->quantity[i];
                found=true;
            }
        }
        if(!found){
            cout<<endl;
            cout<<input->item_code[i]<<" this code is not valid.please enter code again."<<endl;
            return;
        }
    }
    double tax=sum*0.05;
    cout<<"TAX"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t"<<tax<<endl;
    cout<<"_____________________________________________________________________________________________________________________"<<endl;
    double net_total=sum+tax;
    cout<<"NET TOTAL"<<"\t\t\t\t\t\t\t\t\t\t\t\t"<<net_total<<" Taka"<<endl;
    food_item->add_tax(net_total);
}
int main(){
    Restaurant *food_item=Food_Item();
    show_food_item(food_item);
    User *input=input_user();
    bill_summary(food_item,input);
    return 0;
}
