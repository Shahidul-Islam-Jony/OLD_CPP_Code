#include<bits/stdc++.h>
using namespace std;
int *replace(int A[],int n){
    for(int i=0;i<n;i++){
        if(A[i]%3==0){
            A[i]=-1;
        }
    }
    return A;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    replace(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
