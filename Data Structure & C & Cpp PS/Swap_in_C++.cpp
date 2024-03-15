#include<bits/stdc++.h>
using namespace std;
int main(){
    int ar[5]={1,3,5,4,2},n=5;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           /* int temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;*/
            swap(ar[i],ar[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}
