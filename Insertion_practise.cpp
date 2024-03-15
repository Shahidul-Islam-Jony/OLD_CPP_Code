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
    cout<<"Before insert "<<endl;
    printArray(array,size);

    //unsorted insertion...
    int pos;
    cout<<"Enter the position of insertion :";
    cin>>pos;
    int val;
    cout<<"Enter the value of insertion :";
    cin>>val;
    if(pos<0 || pos>size){
        cout<<"Invalid position "<<endl;
        return 0;
    }
    array[size]=array[pos];
    array[pos]=val;
    cout<<"After insertion "<<endl;
    printArray(array,size+1);
    return 0;
}
