#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        //bubble sort..
        for(int i=1;i<n;i++){
            int flag=0;
            for(int j=0;j<n-i;j++){
                if(a[j]>a[j+1]){
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0){
                break;
            }
        }
        int count=1;
        for(int i=0;i<n;i++){
            if(a[i]==a[i+1]){
                count++;
            }
            else{
                break;
            }
        }
        //cout<<count<<endl;
        cout<<n-count;
        cout<<endl;
    }
    return 0;
}
