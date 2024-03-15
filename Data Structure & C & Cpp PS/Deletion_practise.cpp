#include<bits/stdc++.h>
using namespace std;
void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Array before deletion : "<<endl;
    printArray(array,size);
    int pos;
    cout<<"Enter position for deletion : ";
    cin>>pos;
    if(pos<0 || pos>size-1){
        cout<<"Invalid position"<<endl;
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
    cout<<"Array after deletion:"<<endl;
    printArray(array,size);
    return 0;
}
