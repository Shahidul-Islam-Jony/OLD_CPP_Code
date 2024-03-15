// practice //
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[],int val,int l,int r){
    if(l<=r){
        int mid=(l+r)/2;
        if(array[mid]==val){
            return mid;
        }
        else if(array[mid]<val){
            binarySearch(array,val,mid+1,r);
        }
        else{
            binarySearch(array,val,l,mid-1);
        }
    }
    else return -1;
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int val;
    cin>>val;
    int x=binarySearch(array,val,0,n-1);
    if(x==-1){
        cout<<"Value not found"<<endl;
    }
    else{
        cout<<"Value found at position = "<<x+1<<endl;
    }
    return 0;
}
