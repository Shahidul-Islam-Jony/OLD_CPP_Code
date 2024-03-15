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
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i==0&&j<n/2) || (j==0&&i>n/2) || (j==n-1&&i<n/2) || (i==n-1&&j>n/2) || (i==n/2) || (j==n/2)){
               // cout<<array[i][j]<<" ";
                sum+=array[i][j];
            }
        }
    }
    cout<<"Summation = "<<sum<<endl;

    return 0;
}
