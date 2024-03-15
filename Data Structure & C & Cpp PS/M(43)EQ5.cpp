#include<bits/stdc++.h>
using namespace std;


int main()
{
    int Y;
    cin>>Y;
    int p=1;
    long long int sum=0;
    if(Y==1)
    {
        cout<<1<<endl;
    }
    else
    {
        for(int i=2; i<=Y; i++)
        {
            sum=pow(2,p);
            p=p+2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
