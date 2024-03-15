#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;

    int left=0,right=n-1;
    bool found=false;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==target){
            cout<<"Found at index "<<mid<<endl;
            found=true;
            break;
        }
        if(target<a[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    if(found==false){
        cout<<"Not found "<<endl;
    }

    return 0;
}
