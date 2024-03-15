#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

    for(int i=2; i<n; i++)
    {
//        if(i==2) cout<<"2"<<" ";
        int flag=0;
        int j=2;
        for(int j=2; j<i; j++)
        {
            if(i%j==0 && j<i)
            {
                flag=1;
            }
        }
        if(flag==0) cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
