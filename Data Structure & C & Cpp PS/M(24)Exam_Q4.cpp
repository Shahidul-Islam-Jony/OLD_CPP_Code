#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int A[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>A[i][j];
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int key=A[i][j];
            for(int k=0; k<m; k++)
            {
                for(int l=0; l<n; l++)
                {
                    if(key==A[k][l] && (i!=k||j!=l))
                    {
                        A[k][l]=-1;
                    }
                }
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i][j]==-1) cout<<" ";
            else cout<<"  ";
            cout<<A[i][j];
        }
        cout<<endl;
    }

    return 0;
}

