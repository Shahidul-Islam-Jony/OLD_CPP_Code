#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x=sqrt(n);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
