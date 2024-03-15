#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>array[i][j];
        }
    }
    cout<<"Major diagonal : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<array[i][j]<<" ";
            }
        }
    }
    cout<<endl;
    cout<<"Minor diagonal : ";
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(j==n-i-1){
                cout<<array[i][j]<<" ";
            }
        }
    }

    return 0;
}
