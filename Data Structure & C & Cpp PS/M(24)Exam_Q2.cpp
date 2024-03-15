//M(24)Lab Exam Q2 Answer..
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    int m;
    cin>>m;
    int B[m];
    for(int i=0; i<m; i++)
    {
        cin>>B[i];
    }
    for(int i=0; i<n; i++)
    {
        int flag=0;
        for(int j=0; j<m; j++)
        {
            if(A[i]==B[j])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<A[i]<<" ";
        }
    }
    return 0;
}
