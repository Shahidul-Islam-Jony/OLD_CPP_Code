#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<":"<<endl;
        int n,q;
        cin>>n>>q;
        int array[n];
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        flag:
        int pre[n];
        pre[0]=array[0];
        for(int i=1; i<n; i++)
        {
            pre[i]=array[i]+pre[i-1];
        }
//        for(int i=0; i<n; i++)
//        {
//            cout<<pre[i]<<" ";
//        }
        for(int k=0;k<q;k++){
            int a,i,j,v;
            cin>>a;
            if(a==1){
                cin>>i;
                cout<<array[i]<<endl;
                array[i]=0;
                goto flag;
            }
            else if(a==2){
                cin>>i>>v;
                array[i]+=v;
                //cout<<array[i]<<"\n";
                goto flag;
            }
            else if(a==3){
                cin>>i>>j;
                cout<<pre[j]-pre[i-1]<<endl;
                goto flag;
            }
            else{
                break;
            }
        }
        //by faster i/o...
    }
    return 0;
}
