#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(int A[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]==A[j]){
                if(j==n-1)  n--;
                else{
                    while(j<=n){
                        A[j]=A[j+1];
                        j++;
                    }
                    n--;
                }
            }
            else{
                continue;
            }
        }
        if(A[i]==A[i-1])    n--;
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}


int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    removeDuplicate(A,n);
}
