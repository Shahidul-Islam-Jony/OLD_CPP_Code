#include<bits/stdc++.h>
using namespace std;

void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array[50];

    int size;
    cin>>size;

    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Before deletion5 "<<endl;
    printArray(array,size);

    //deletion....
    int pos;
    cout<<"Position of the deletion : ";
    cin>>pos;

    if(pos<0 || pos>size-1){
        cout<<"Invalid index"<<endl;
        return 0;
    }
    else{
        if(pos==size-1) size--;
        else{
            for(int i=pos+1;i<size;i++){
                array[i-1]=array[i];
            }
            size--;
        }
    }
    cout<<"After deletion"<<endl;
    printArray(array,size);

    return 0;
}


