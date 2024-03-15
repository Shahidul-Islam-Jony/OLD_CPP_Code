#include<iostream>
using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,q;
        cin>>n>>q;
        int array[n];
        for(int i=0; i<n; i++)
        {
            cin>>array[i];
        }
        int I,J;
        for(int i=0; i<q; i++)
        {
            cin>>I>>J;
        }
        //insertion sort...
        for(int i=1; i<n; i++)
        {
            int key=array[i];
            int j=i-1;
            while(array[j]>key && j>=0){
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=key;
        }
        cout<<"Case "<<i+1<<":"<<"\n";
        for(int j=0; j<q; j++)
        {
            cout<<array[j]<<"\n";
        }
    }

    return 0;
}
