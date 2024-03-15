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
    printArray(array,size);
    return 0;
}
