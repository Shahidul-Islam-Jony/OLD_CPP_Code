#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int i=0; i<T; i++)
    {
        int D;
        cin>>D; //Days..
        int earned[D];
        int spent[D];
        //Earning amount..
        for(int i=0; i<D; i++)
        {
            cin>>earned[i];
        }
        //spending amount...
        for(int i=0; i<D; i++)
        {
            cin>>spent[i];
        }
        //Queries..
        int Q;
        cin>>Q;
        for(int i=0; i<Q; i++)
        {
            int x;
            cin>>x;
            int balance=0;
            for(int j=0; j<=x; j++)
            {
                balance+=earned[j]-spent[j];
            }
            if(balance>=0)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
