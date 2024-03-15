#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,col,i,j;
    cin>>row>>col;
    int a[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    int req_col;
    cin>>req_col;
    for(int i=0;i<row;i++){
        cout<<a[i][req_col]<<" ";
    }
    cout<<endl;
    int req_row;
    cin>>req_row;
    for(int j=0;j<col;j++){
        cout<<a[req_row][j]<<" ";
    }
    return 0;
}
