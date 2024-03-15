#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int array[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>array[i][j];
        }
    }
    cout<<endl;
    int x=m*n;
    int arr[x];
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[k]=array[i][j];
            k++;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            if(arr[i]==arr[j]){
                arr[j]=-1;
            }
        }
    }
    int count=0;
    for(int i=0;i<x;i++){
        if(arr[i]==-1 && count!=0){
            cout<<" ";
        }
        if(arr[i]!=-1 && count==0){
            cout<<" ";
        }
        if(arr[i]!=-1 && count!=0){
            cout<<"  ";
        }
        cout<<arr[i];
        count++;
        if(count==n){
            cout<<endl;
            count=0;
        }
    }
    return 0;
}
