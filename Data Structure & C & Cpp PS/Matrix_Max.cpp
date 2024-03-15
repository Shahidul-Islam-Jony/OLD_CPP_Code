#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int max=a[0][0];
    int k,l;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(max<a[i][j]){
                max=a[i][j];
                k=i;
                l=j;
            }
        }
    }
    cout<<"Max = "<<max<<endl;
    cout<<"Location = "<<"["<<k<<"]"<<"["<<l<<"]"<<endl;

    return 0;
}
