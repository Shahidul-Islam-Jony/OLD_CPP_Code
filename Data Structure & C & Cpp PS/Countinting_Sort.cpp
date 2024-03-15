#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    int count[max+1]={0};

    for(int i=0;i<n;i++){
        count[array[i]]++;
    }

    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    for(int i=0;i<=max;i++){
        cout<<count[i]<<" ";
    }

//    int final[n];
//    for(int i=n-1;i>=0;i--){
//        count[array[i]]--;
//        int k=count[array[i]];
//        final[k]=array[i];
//    }
//
//    for(int i=0;i<n;i++){
//        cout<<final[i]<<endl;
//    }

    return 0;
}
