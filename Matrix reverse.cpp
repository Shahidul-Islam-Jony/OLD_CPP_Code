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
    cout<<endl<<endl;
    for(int i=0;i<m;i++){
        for(int j=n-1;j>=0;j--){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
