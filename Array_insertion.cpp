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
    cout<<"Before insertion "<<endl;
    printArray(array,size);

    //Insertion for sorted Array....
    int pos;
    cout<<"Position of the insertion : ";
    cin>>pos;
    int val;
    cout<<"Value of the insertion : ";
    cin>>val;

    if(pos<0 || pos>size){
        cout<<"Invalid index"<<endl;
    }
    else{
        //size-1----->pos
        for(int i=size-1;i>=pos;i--){
            array[i+1]=array[i];
        }
        array[pos]=val;
    }
    cout<<"After Insertion "<<endl;
    printArray(array,size+1);

    return 0;
}

