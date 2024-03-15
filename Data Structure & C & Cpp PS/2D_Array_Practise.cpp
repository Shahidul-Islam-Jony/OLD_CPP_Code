#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    int array[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>array[i][j];
        }
    }

    cout<<endl;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<array[j][i]<<" ";
        }
        cout<<endl;
    }
}
