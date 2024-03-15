#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    char c;
    cout<<"Do you want to search : (Y/N) : ";
    cin>>c;
    while(toupper(c)=='Y'){
        int find;
        cout<<"which number do you want to find :";
        cin>>find;
        int flag=0;
        for(int i=0;i<size;i++){
            if(array[i]==find){
                cout<<"index "<<i<<" position "<<i+1<<endl;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"Not found "<<endl;
        }
        cout<<"Do you want to search again : (Y/N) : ";
        cin>>c;
    }
    return 0;
}

