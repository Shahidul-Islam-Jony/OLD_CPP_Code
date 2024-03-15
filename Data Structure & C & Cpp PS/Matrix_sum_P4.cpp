#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<endl;
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1){
                sum+=a[i][j];
                //cout<<a[i][j]<<" ";
            }
            if(i==j && i!=0 && i!=n-1){
                sum+=a[i][j];
                //cout<<a[i][j]<<" ";
            }
            if(j!=n-1 && i!=n-1 && i==n-j){
                sum+=a[i][j];
            }
            if(i==n/2  && i==j){
                sum-=a[i][j];
            }
        }
    }
    cout<<endl;
    cout<<"Sum = "<<sum<<endl;
    return 0;
}
