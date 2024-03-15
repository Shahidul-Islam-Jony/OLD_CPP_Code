#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n;
        cin>>n;
        int arr[2*n+1];

        int odd=0;
        for(int i=0;i<2*n;i++){
            cin>>arr[i];

            if(arr[i]%2!=0){
                odd++;
            }
        }
        if(odd<n){
            cout<<"No"<<endl;
        }
        else if(odd==n){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}
