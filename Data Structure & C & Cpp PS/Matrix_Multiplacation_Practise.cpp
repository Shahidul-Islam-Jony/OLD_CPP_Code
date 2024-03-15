#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    int a[r][c],b[r][c],mul[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>b[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mul[i][j]=0;
            for(int k=0;k<c;k++){
                mul[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
