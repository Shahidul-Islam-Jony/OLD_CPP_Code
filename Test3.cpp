#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l[n+1], r[n+1];
    for(int i=1; i<=n; i++){
        cin>>l[i]>>r[i];
    }


    int temp=0;
    for(int i=1; i<=n; i++)
    {
        if(l[i] == 0)
        {
            cout<<"Now li= "<<l[i]<<endl<<endl;
            if(temp != 0)
            {
                cout<<"Now i= "<<i<<endl<<endl;
                l[i]=temp;
                cout<<"l[i]= "<<l[i]<<endl<<endl;
                r[temp]=i;
                cout<<"r[temp]= "<<r[temp]<<endl<<endl;
            }
            temp=i;
            cout<<"Now temp = i "<<temp<<endl<<endl;
            while(r[temp]){
                temp=r[temp];
                cout<<" while temp=r[temp] "<<temp<<endl<<endl;
            }

        }
    }
    cout<<endl<<endl;
    for(int i=1; i<=n; i++){
        cout<<l[i]<<" "<<r[i]<<endl;
    }

    return 0;
}
