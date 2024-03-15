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
    cout<<"Before sort : "<<endl;
    printArray(array,size);
    int max=INT_MIN;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    int count[max+1]={0};
    for(int i=0;i<size;i++){
        count[array[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    int final[size];
    for(int i=size-1;i>=0;i--){
            cout<<count[array[i]]<<" ";
        count[array[i]]--;
        int k=count[array[i]];
        final[k]=array[i];
    }
    cout<<"After sort : "<<endl;
    printArray(final,size);
}
